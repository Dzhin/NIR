#include <vcl.h>
#pragma hdrstop
#include "bmpfile.h"


fileReturnedCode BmpFile::OpenFile(const char* fileName,
const long verSize, const long horSize, const int pixelBitNumber)
{
	fileReturnedCode rc=frcOk;
	if( pixelBitNumber==1 || pixelBitNumber==4 || pixelBitNumber==8 )
	{
		rc=OpenNew(fileName, verSize, horSize, pixelBitNumber,
		GetOffset(pixelBitNumber), __BmpFileExtension);
	}
	else
		rc=frcWrongPixelBitNumber;
	return rc;
}

int BmpFile::GetAddStringByteNumber(long StringByteNumber)
{
	int n=(int)(StringByteNumber%__BmpStringLengthDeliver);
	if( n!=0 ) n=__BmpStringLengthDeliver-n;
	return n;
}

fileReturnedCode BmpFile::ReadShape(long fileByteNumber)
{
	fileReturnedCode rc=frcOk;
	int li=sizeof(unsigned short int), ll=sizeof(unsigned long);
	char BM[3]; BM[2]=0;
	unsigned long lFileSize, lTmp, lOffset;
	unsigned long lSize, lHorSize, lVerSize;
	unsigned short int  biPlanes, biBitCount;
	if( (rc=SetBegining())==frcOk &&
		(rc=Read(BM, li))==frcOk && BM[0]=='B' && BM[1]=='M' &&
		(rc=Read(&lFileSize, ll))==frcOk && lFileSize<=(unsigned long) fileByteNumber &&
		(rc=Read(&lTmp, ll))==frcOk &&
		(rc=Read(&lOffset, ll))==frcOk &&
		(rc=Read(&lSize, ll))==frcOk && lSize==0x28 &&
		(rc=Read(&lHorSize, ll))==frcOk &&
		(rc=Read(&lVerSize, ll))==frcOk &&
		(rc=Read(&biPlanes, li))==frcOk && biPlanes==1 &&
		(rc=Read(&biBitCount, li))==frcOk &&
		(rc=Read(&lTmp, ll))==frcOk && lTmp==0 &&
		(unsigned long) GetFileSize(lVerSize, lHorSize, biBitCount)==lFileSize)
	{
		int off=GetOffset(biBitCount);
		if( off )
		{
			SetTitleOffset(off);
			Set(lVerSize, lHorSize, biBitCount);
		}
		else
			rc=frcWrongPixelBitNumber;
	}
	else
		rc=frcWrongFileStructure;
	return rc;
}

fileReturnedCode BmpFile::WriteShape(long TitleAndPictureByteNumber)
{
	fileReturnedCode rc=frcOk;
	int off=GetOffset(PixelBitNumber);
	long length=GetFileSize(VerSize, HorSize, PixelBitNumber);
	if( length==TitleAndPictureByteNumber )
	{
		char BM[3]="BM";
		int li=sizeof(unsigned short int), ll=sizeof(unsigned long);
		unsigned long lFileSize=TitleAndPictureByteNumber, lTmp=0, lOffset=off;
		unsigned long lSize=0x28, lHorSize=HorSize, lVerSize=VerSize;
		unsigned short int  biPlanes=1;
		unsigned short int  biBitCount=(unsigned short int)PixelBitNumber;
		if( (rc=SetBegining())==frcOk &&
			(rc=Write(BM, li))==frcOk &&
			(rc=Write(&lFileSize, ll))==frcOk &&
			(rc=Write(&lTmp, ll))==frcOk &&
			(rc=Write(&lOffset, ll))==frcOk &&
			(rc=Write(&lSize, ll))==frcOk &&
			(rc=Write(&lHorSize, ll))==frcOk &&
			(rc=Write(&lVerSize, ll))==frcOk &&
			(rc=Write(&biPlanes, li))==frcOk &&
			(rc=Write(&biBitCount, li))==frcOk &&
			(rc=Write(&lTmp, ll))==frcOk &&
			(rc=Write(&lTmp, ll))==frcOk &&
			(rc=Write(&lTmp, ll))==frcOk &&
			(rc=Write(&lTmp, ll))==frcOk &&
			(rc=Write(&lTmp, ll))==frcOk &&
			(rc=Write(&lTmp, ll))==frcOk)
		{
			// запись палитры
			int n=1;
			for(int i=0; i<PixelBitNumber; i++)
				n*=2;
			unsigned long p=0, max=0x00ffffffL, ps=max/(n-1);
			for(int i=0; i<n && rc==frcOk; i++)
			{
				rc=Write(&p, ll);
				if( i<n-1 )
					p+=ps;
			}
		}
		else
			rc=frcWriteError;
	}
	else
		rc=frcWrongFileSize;
	return rc;
}

int BmpFile::GetOffset(int pt)
{
	int off=0;
	switch (pt)
	{
		case 1:
			off=0x3E;
			break;
		case 4:
			off=0x76;
			break;
		case 8:
			off=0x436;
			break;
		default:
			off=0;
	}
	return off;
}

long BmpFile::GetFileSize(long vn, long hn, int pt)
{
	int off=GetOffset(pt);
	long l1=hn*pt, l=l1/8+((l1%8) ? 1 : 0);
	long length=vn*(l+GetAddStringByteNumber(l))+off;
	return length;
}
