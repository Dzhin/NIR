#ifndef __AnyFile__
#define __AnyFile__

enum fileReturnedCode
{
	frcOk=0,
	frcFileOpenError,
	frcWrongPixelBitNumber,
	frcReadError,
	frcWriteError,
	frcLseekError,
	frcWrongStringIndex,
	frcNoMemory,
	// для последующих классов
	frcWrongFieldSize,
	frcWrongFileSize,
	frcNoCommentUnit,
	frcWrongFileStructure,
	frcUndefinedFieldSize,
	frcLast
};

// все методы не Get* возвращают fileReturnedCode
#define __CloseFileToggle -1

class AnyFile
{
	int file, ifNewToggle, TitleOffset;
	long StringByteNumber;
	int  AddStringByteNumber;
protected:
	int PixelBitNumber;
	long VerSize, HorSize;
	AnyFile() : file(__CloseFileToggle),
      PixelBitNumber(0), VerSize(0), HorSize(0), StringByteNumber(0) {}
	~AnyFile();
	// FileExtent с точкой (например: ".dat")
	// fileName может не содержать расширения
	fileReturnedCode OpenNew(const char* fileName,
		const long verSize, const long horSize, const int pixelBitNumber,
		const int titleOffset, const char* FileExtent);

	fileReturnedCode OpenOld(const char* fileName,
		const long verSize, const long horSize, const int pixelBitNumber,
		const int titleOffset, const char* FileExtent);

	fileReturnedCode OpenOld(const char* fileName,
		const int titleOffset, const char* FileExtent);

private:
	fileReturnedCode VerifyNewPixelBitNumber(int pt);
	fileReturnedCode OpeFileByName(const char* fileName, const char *FileExtent, const int a, const unsigned m);
	void ClearFile();

protected:
	void Set(const long verSize, const long horSize, const int pixelBitNumber);
	// для случая переменной длины заголовка (BMP)
	void SetTitleOffset(const int newOffset)
	{
		TitleOffset=newOffset;
	}
public:
	int  isOpen()              { return file != __CloseFileToggle;  }
	long GetVerSize()          { return VerSize; }
	long GetHorSize()          { return HorSize; }
	int  GetPixelBitNumber()   { return PixelBitNumber; }
	long GetStringByteNumber() { return StringByteNumber; }
	// в случае <число бит/пиксел> <8 строка распаковывается (упаковывается)
	// в тот же буфер и может быть использована в *PackedString(...)
	fileReturnedCode ReadString(void* buf);
	fileReturnedCode WriteString(void* buf);
	fileReturnedCode ReadString(long index, void* buf)
	{
		fileReturnedCode rc=SetToString(index);
		return (rc==frcOk) ? ReadString(buf) : rc;
	}
	fileReturnedCode WriteString(long index, void* buf)
	{
		fileReturnedCode rc=SetToString(index);
		return (rc==frcOk) ? WriteString(buf) : rc;
	}
	fileReturnedCode ReadPackedString(void* buf);
	fileReturnedCode WritePackedString(void* buf);
	fileReturnedCode ReadPackedString(int index, void* buf)
	{
		fileReturnedCode rc=SetToString(index);
		return (rc==frcOk) ? ReadPackedString(buf) : rc;
	}
	fileReturnedCode WritePackedString(int index, void* buf)
	{
		fileReturnedCode rc=SetToString(index);
		return (rc==frcOk) ? WritePackedString(buf) : rc;
	}
	void CloseFile();
	virtual char* GetMessage(fileReturnedCode frc);

protected:
	unsigned char* GetPointer(unsigned char* b, long off);
	void BitToByte(void* buf);
	void ByteToBit(void* buf);
	fileReturnedCode  Read(void* buf, long byteNumber);
	fileReturnedCode  Write(void* buf, long byteNumber);
	fileReturnedCode SetToString(long index);
	fileReturnedCode SetAfterLastString();
	fileReturnedCode SetBegining();
	virtual void ChangeConvertMask(unsigned char mask[8])
	{
		mask[0]=mask[0];
	}
	// использовать при выравнии числа байт в строке
	virtual int GetAddStringByteNumber(long _StringByteNumber)
	{
		_StringByteNumber=_StringByteNumber;
		return 0;
	}
	virtual fileReturnedCode ReadShape(long fileByteNumber)=0;
	virtual fileReturnedCode WriteShape(long TitleAndPictureByteNumber)=0;

public:
	virtual fileReturnedCode  OpenFile(const char* fileName)=0;
	virtual fileReturnedCode  OpenFile(const char* fileName,
		const long verSize, const long horSize, const int pixelBitNumber)=0;
};

#endif
