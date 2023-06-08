#pragma once
#include <stdint.h>
#include <stdio.h>

typedef struct {
	uint16_t bfType; //specifies the file type, WORD
	uint32_t bfSize; //specifies the size in bytes of the bitmap file, DWORD
	uint16_t bfReserved1; //reserved; must be 0
	uint16_t bfReserved2; //reserved; must be 0
	uint32_t bfOffBits; //specifies the offset in bytes from the bitmapfileheader to the bitmap bits
} BitmapFileHeader;

typedef struct {
	uint32_t biSize;
	uint32_t biWidth;
	uint32_t biHeight;
	uint16_t biPlanes;
	uint16_t biBitCount;
	uint32_t biCompression;
	uint32_t biSizeImage;
	uint32_t biXPelsPerMeter;
	uint32_t biYPelsPerMeter;
	uint32_t biClrUsed;
	uint32_t biClrImportant;
} BITMAPINFOHEADER;

typedef struct {
	uint8_t* blue;
	uint8_t* green;
	uint8_t* red;
	uint8_t* reserved;
}RGBQuads;

void recolor(RGBQuads rgb, BITMAPINFOHEADER bih);

class bmp {
private:
	BitmapFileHeader bfh;
	BITMAPINFOHEADER bih;
	RGBQuads rgb;
public:
	bmp();
	void read(FILE* fin);
	void recolor();
	void write(FILE* fout);
};