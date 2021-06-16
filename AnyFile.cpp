#include <vcl.h>
#pragma hdrstop
#include <fcntl.h>
#include <sys/stat.h>
#include <io.h>
#include <string.h>
#include <windows.h>

#include "anyfile.h"

#define ByteLength 8
#define Bit1 1
#define Bit2 2
#define Bit4 4

AnyFile::~AnyFile() 
{ 
	if( file!=__CloseFileToggle )
		close(file);
}

fileReturnedCode AnyFile::OpenNew(const char* fileName,
   const long verSize, const long horSize, const int pixelBitNumber,
   const int titleOffset, const char* FileExtent) 
{
	fileReturnedCode rc=frcOk;
	if( (rc=VerifyNewPixelBitNumber(pixelBitNumber))==frcOk ) 
	{
		int access=O_CREAT | O_BINARY | O_TRUNC | O_RDWR;
		unsigned mode=S_IREAD | S_IWRITE;
		if( (rc=OpeFileByName(fileName, FileExtent, access, mode))==frcOk ) 
		{
			TitleOffset=titleOffset;
			Set(verSize, horSize, pixelBitNumber);
			rc=SetToString(0);
		}
	}
	return rc;
}

fileReturnedCode AnyFile::OpenOld(const char* fileName,
   const long verSize, const long horSize, const int pixelBitNumber,
   const int titleOffset, const char* FileExtent) 
{
	fileReturnedCode rc=frcOk;
	int access=O_BINARY | O_RDWR;
	unsigned mode=S_IREAD|S_IWRITE;
	if( (rc=OpeFileByName(fileName, FileExtent, access, mode))==frcOk ) 
	{
		Set(verSize, horSize, pixelBitNumber);
		TitleOffset=titleOffset;
		if( ( rc=ReadShape( filelength(file) ) )==frcOk ) 
		{
			if( (rc=VerifyNewPixelBitNumber(PixelBitNumber))==frcOk ) 
			{
				rc=SetToString(0);
			}
		}
		if( rc!=frcOk ) 
		{
			if( file!=__CloseFileToggle ) 
				close(file);
			file=__CloseFileToggle;
//			CloseFile();
		}
	}
	return rc;
}

fileReturnedCode AnyFile::OpenOld(const char* fileName, const int titleOffset, const char* FileExtent) 
{
	return AnyFile::OpenOld(fileName, 0, 0, 0, titleOffset, FileExtent);
}

fileReturnedCode AnyFile::VerifyNewPixelBitNumber(int pt) 
{
	fileReturnedCode rc=frcOk;
	if( pt>ByteLength && pt%ByteLength ||
	pt<ByteLength && pt!=Bit1 && pt!=Bit2 && pt!=Bit4 ) 
	{
		rc=frcWrongPixelBitNumber;
	}
	return rc;
}

fileReturnedCode AnyFile::OpeFileByName(const char* fileName, const char *FileExtent, const int a, const unsigned m) 
{
	if( file!=__CloseFileToggle ) 
		CloseFile();
	fileReturnedCode rc=frcOk;
	char *s=new char[strlen(fileName)+4];
	if( s ) 
	{
		strcpy(s, fileName);
		int i=0,j=0;
		// удаление пробелов
		char c=1;
		while(c!=0)
		{
			c=s[i++];
			if(c!=' ')
				s[j++]=c;
		}
		// добавление расширения если не было
		char *p=strrchr(s,'\\');
		if ( !strchr( (p)? p : s ,'.') )  
			strcat ( s, FileExtent );
		strupr(s);
		file=open(s, a, m);
		if( file==__CloseFileToggle ) 
			rc=frcFileOpenError;
		delete s;
	}
	else 
		rc=frcNoMemory;
	return rc;
}

void AnyFile::ClearFile() 
{
	chsize(file, 0);
}

void AnyFile::Set(const long verSize, const long horSize, const int pixelBitNumber) 
{
	VerSize=verSize;
	HorSize=horSize;
	PixelBitNumber=pixelBitNumber;
	long l=HorSize*PixelBitNumber, ll=l/8 + ((l%8) ? 1 : 0);
	AddStringByteNumber=GetAddStringByteNumber(ll);
	StringByteNumber=ll;
}

// в случае <число бит/пиксел> <8 строка распаковывается (упаковывается)
// в тот же буфер и может быть использована в *PackedString(...)
fileReturnedCode AnyFile::ReadString(void* buf) 
{
	fileReturnedCode rc=frcOk;
	rc=Read(buf, StringByteNumber);

	char c0=0;
	for(int i=0; i<AddStringByteNumber && rc==frcOk; i++) 
	{
		if( read(file, &c0, 1)!=1 )
			rc=frcReadError;
	}
	if( PixelBitNumber<ByteLength )
		BitToByte(buf);
	return rc;
}

fileReturnedCode AnyFile::WriteString(void* buf) 
{
	fileReturnedCode rc=frcOk;
	if( PixelBitNumber<ByteLength )
		ByteToBit(buf);
	rc=Write(buf, StringByteNumber);

	char c0=0;
	for(int i=0; i<AddStringByteNumber && rc==frcOk; i++) 
	{
		if( write(file, &c0, 1)!=1 )
			rc=frcWriteError;
	}
	return rc;
}

fileReturnedCode AnyFile::ReadPackedString(void* buf) 
{
	fileReturnedCode rc=Read(buf, StringByteNumber);

	char c0=0;
	for(int i=0; i<AddStringByteNumber && rc==frcOk; i++) 
	{
		if( read(file, &c0, 1)!=1 )
			rc=frcReadError;
	}
	return rc;
}

fileReturnedCode AnyFile::WritePackedString(void* buf) 
{
	fileReturnedCode rc=Write(buf, StringByteNumber);

	char c0=0;
	for(int i=0; i<AddStringByteNumber && rc==frcOk; i++)
	{
		if( write(file, &c0, 1)!=1 ) 
			rc=frcWriteError;
	}
	return rc;
}

void AnyFile::CloseFile() 
{
	if( WriteShape(filelength(file))!=frcOk )
		ClearFile();
	if( file!=__CloseFileToggle )
		close(file);
	file=__CloseFileToggle;
	VerSize=0;
	HorSize=0;
	PixelBitNumber=0;
	StringByteNumber=0;
}

static char diaOk[]="Ok";
static char diaFileOpenError[]="FileOpenError";
static char diaWrongPixelBitNumber[]="WrongPixelBitNumber";
static char diaReadError[]="ReadError";
static char diaWriteError[]="WriteError";
static char diaLseekError[]="LseekError";
static char diaWrongStringIndex[]="WrongStringIndex";
static char diaNoMemory[]="NoMemory";
//static char diaWrongFieldSize[]="WrongFieldSize";
static char diaWrongFileSize[]="WrongFileSize";
static char diaNoCommentUnit[]="NoCommentUnit";
static char diaWrongFileStructure[]="WrongFileStructure";
static char diaDefault[]="UnknownError";

char* AnyFile::GetMessage(fileReturnedCode frc)
{
	char *s;
	switch (frc)
	{
		case frcOk:                  s=diaOk;                   break;
		case frcFileOpenError:       s=diaFileOpenError;        break;
		case frcWrongPixelBitNumber: s=diaWrongPixelBitNumber;  break;
		case frcReadError:           s=diaReadError;            break;
		case frcWriteError:          s=diaWriteError;           break;
		case frcLseekError:          s=diaLseekError;           break;
		case frcWrongStringIndex:    s=diaWrongStringIndex;     break;
		case frcNoMemory:            s=diaNoMemory;             break;
//		case frcWrongFieldSize:      s=diaWrongFieldSize;       break;
		case frcWrongFileSize:       s=diaWrongFileSize;        break;
		case frcNoCommentUnit:       s=diaNoCommentUnit;        break;
		case frcWrongFileStructure:  s=diaWrongFileStructure;   break;
		default:                     s=diaDefault;
	}
	return s;
}

static unsigned int MaxBufferLength=0xfff0;

unsigned char* AnyFile::GetPointer(unsigned char* b, long off)
{
	long l=off;
	unsigned char* c=b;
	while((unsigned long) l>MaxBufferLength )
	{
		c+=(unsigned int)MaxBufferLength;
		l-=MaxBufferLength;
	}
	c+=(unsigned int)l;
	return c;
}

void AnyFile::BitToByte(void* buf)
{
	unsigned char m[8]={0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1};
	ChangeConvertMask(m);
	unsigned char *from=(unsigned char *)buf, *to=from;

	to=GetPointer(to, HorSize-1);
	from=GetPointer(from, GetStringByteNumber()-1);
	int li=(int)( (HorSize*PixelBitNumber)%8 );
	if( li==0 ) 
		li=8;
	switch (PixelBitNumber)
	{
		case Bit1:
			while( to>buf )
			{
				unsigned char c=*from--;
				for(int i=li-1; i>=0; i--)
				{
					*to--=(( c&m[i] ) ? 0xFF : 0);
				}
				li=8;
			}
			break;
		case Bit2:
			while( to>buf )
			{
				unsigned char c=*from--;
				for(int j=li-1; j>0; j-=2)
				{
					unsigned char cc=0;
					if( c&m[j-1] ) 
						cc+=0xAA; //0x80;
					if( c&m[j  ] )
						cc+=0x55; //0x40;
					*to--=cc;
				}
				li=8;
			}
			break;
		case Bit4:
			while( to>buf )
			{
				unsigned char c=*from--;
				for(int j=li-1; j>2; j-=4)
				{
					unsigned char cc=0;
					if( c&m[j-3] )
						cc+=0x88; //0x80;
					if( c&m[j-2] )
						cc+=0x44; //0x40;
					if( c&m[j-1] )
						cc+=0x22; //0x20;
					if( c&m[j  ] )
						cc+=0x11; //0x10;
					*to--=cc;
				}
				li=8;
			}
			break;
		default:;
	}
}

void AnyFile::ByteToBit(void* buf)
{
	unsigned char m[8]={0x80, 0x40, 0x20, 0x10, 8, 4, 2, 1};
	ChangeConvertMask(m);
	long n=HorSize;
	unsigned char *from=(unsigned char *)buf, *to=from;
	switch (PixelBitNumber)
	{
		case Bit1:
			while(n>0)
			{
				int nn=(n>8) ? 8 : (int)n;
				unsigned char c=0;
				for(int i=0; i<nn; i++)
				{
					if( (*from++)&0x80 )
						c+=m[i];
				}
				*to++=c;
				n-=nn;
			}
			break;
		case Bit2:
			while(n>0)
			{
				int nn=(n>4) ? 4 : (int)n;
				unsigned char c=0;
				for(int i=0, j=0; i<nn; i++, j+=2)
				{
					unsigned char cc=*from++;
					if( cc&0x80 )
						c+=m[j];
					if( cc&0x40 )
						c+=m[j+1];
				}
				*to++=c;
				n-=nn;
			}
			break;
		case Bit4:
			while(n>0)
			{
				int nn=(n>2) ? 2 : (int)n;
				unsigned char c=0;
				for(int i=0, j=0; i<nn; i++, j+=4)
				{
					unsigned char cc=*from++;
					if( cc&0x80 )
						c+=m[j];
					if( cc&0x40 )
						c+=m[j+1];
					if( cc&0x20 )
						c+=m[j+2];
					if( cc&0x10 )
						c+=m[j+3];
				}
				*to++=c;
				n-=nn;
			}
			break;
		default:;
	}
}

fileReturnedCode  AnyFile::Read(void* buf, long byteNumber)
{
	fileReturnedCode rc=frcOk;
	char *c=(char*)buf;
	long l=byteNumber;
	while((unsigned long) l>MaxBufferLength && rc==frcOk )
	{
		if((unsigned int) read(file, c, MaxBufferLength)!=MaxBufferLength )
			rc=frcReadError;
		else 
		{
			c-=MaxBufferLength;
			l-=MaxBufferLength;
		}
	}
	if( rc==frcOk && l>0 && read(file, c, (unsigned)l)!=l )
		rc=frcReadError;
	return rc;
}

fileReturnedCode  AnyFile::Write(void* buf, long byteNumber)
{
	fileReturnedCode rc=frcOk;
	char *c=(char*)buf;
	long l=byteNumber;
	while((unsigned long) l>MaxBufferLength && rc==frcOk )
	{
		if((unsigned int) write(file, c, MaxBufferLength)!=MaxBufferLength )
			rc=frcWriteError;
		else
		{
			c-=MaxBufferLength;
			l-=MaxBufferLength;
		}
	}
	if( rc==frcOk && l>0 && write(file, c, (unsigned)l)!=l )
		rc=frcWriteError;
	return rc;
}

fileReturnedCode AnyFile::SetToString(long index)
{
	fileReturnedCode rc=frcOk;
	if( index<VerSize )
	{
		long ll=(StringByteNumber+AddStringByteNumber)*index+TitleOffset;
		if( lseek(file, ll, SEEK_SET)!=ll )
			rc=frcLseekError;
	}
	else
		rc=frcWrongStringIndex;
	return rc;
}

fileReturnedCode AnyFile::SetAfterLastString()
{
	fileReturnedCode rc=frcOk;
	long ll=(StringByteNumber+AddStringByteNumber)*VerSize+TitleOffset;
	if( lseek(file, ll, SEEK_SET)!=ll )
		rc=frcLseekError;
	return rc;
}

fileReturnedCode AnyFile::SetBegining()
{
	fileReturnedCode rc=frcOk;
	if( lseek(file, 0L, SEEK_SET)!=0 )
		rc=frcLseekError;
	return rc;
}
