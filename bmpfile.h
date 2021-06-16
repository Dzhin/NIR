#ifndef __BmpFile__
#define __BmpFile__
#include "anyfile.h"

// все методы не Get* возвращают fileReturnedCode (см. anyfile.h)
#define __BmpFileExtension ".bmp"
#define __BmpStringLengthDeliver 4


class BmpFile : public AnyFile
{
public:
	BmpFile() : AnyFile() {}
	fileReturnedCode OpenFile(const char* fileName,
		const long verSize, const long horSize, const int pixelBitNumber);
	fileReturnedCode OpenFile(const char* fileName)
	{
		return OpenOld(fileName, 5, __BmpFileExtension);
	}
	// Read*, Write* CloseFile см. anyfile.h

protected:
	virtual int GetAddStringByteNumber(long StringByteNumber);
	virtual fileReturnedCode ReadShape(long fileByteNumber);
	virtual fileReturnedCode WriteShape(long TitleAndPictureByteNumber);
	int  GetOffset(int pt);
	long GetFileSize(long vn, long hn, int pt);
};

#endif
