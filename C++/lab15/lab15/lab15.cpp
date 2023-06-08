#include "lab15.h"
#include <stdlib.h>

void recolor(RGBQuads rgb, BITMAPINFOHEADER bih) {
	for (int j = 0; j < bih.biHeight; j++) {
		for (int i = 0; i < bih.biWidth; i++) {
			rgb.blue[j * bih.biWidth + i] = 255 - rgb.blue[j * bih.biWidth + i];
			rgb.green[j * bih.biWidth + i] = 255 - rgb.green[j * bih.biWidth + i];
			rgb.red[j * bih.biWidth + i] = 255 - rgb.red[j * bih.biWidth + i];
		}
	}
}

bmp::bmp() {
	bfh = {'BM', 0, 0, 0, 54};
	bih = { 40,0,0,1,24,0,0,0,0,0,0 };
	rgb = { 0,0,0,0 };
}

void bmp::read(FILE* fin) {
	fread(&bfh.bfType, sizeof(bfh.bfType), 1, fin);
	fread(&bfh.bfSize, sizeof(bfh.bfSize), 1, fin);
	fread(&bfh.bfReserved1, sizeof(bfh.bfReserved1), 1, fin);
	fread(&bfh.bfReserved2, sizeof(bfh.bfReserved2), 1, fin);
	fread(&bfh.bfOffBits, sizeof(bfh.bfOffBits), 1, fin);

	fread(&bih.biSize, sizeof(bih.biSize), 1, fin);
	fread(&bih.biWidth, sizeof(bih.biWidth), 1, fin);
	fread(&bih.biHeight, sizeof(bih.biHeight), 1, fin);
	fread(&bih.biPlanes, sizeof(bih.biPlanes), 1, fin);
	fread(&bih.biBitCount, sizeof(bih.biBitCount), 1, fin);
	fread(&bih.biCompression, sizeof(bih.biCompression), 1, fin);
	fread(&bih.biSizeImage, sizeof(bih.biSizeImage), 1, fin);
	fread(&bih.biXPelsPerMeter, sizeof(bih.biXPelsPerMeter), 1, fin);
	fread(&bih.biYPelsPerMeter, sizeof(bih.biYPelsPerMeter), 1, fin);
	fread(&bih.biClrUsed, sizeof(bih.biClrUsed), 1, fin);
	fread(&bih.biClrImportant, sizeof(bih.biClrImportant), 1, fin);

	rgb.blue = (uint8_t*)malloc(bih.biHeight * bih.biWidth);
	rgb.green = (uint8_t*)malloc(bih.biHeight * bih.biWidth);
	rgb.red = (uint8_t*)malloc(bih.biHeight * bih.biWidth);
	rgb.reserved = (uint8_t*)malloc(bih.biHeight * bih.biWidth);

	for (int j = 0; j < bih.biHeight; j++) {
		for (int i = 0; i < bih.biWidth; i++) {
			fread(&rgb.blue[j * bih.biWidth + i], 1, 1, fin);
			fread(&rgb.green[j * bih.biWidth + i], 1, 1, fin);
			fread(&rgb.red[j * bih.biWidth + i], 1, 1, fin);
		}
		for (int i = 0; i < bih.biWidth % 4; i++) {
			fread(&rgb.reserved[j * bih.biWidth % 4 + i], 1, 1, fin);
		}
	}
}

void bmp::recolor() {
	for (int j = 0; j < bih.biHeight; j++) {
		for (int i = 0; i < bih.biWidth; i++) {
			rgb.blue[j * bih.biWidth + i] = 255 - rgb.blue[j * bih.biWidth + i];
			rgb.green[j * bih.biWidth + i] = 255 - rgb.green[j * bih.biWidth + i];
			rgb.red[j * bih.biWidth + i] = 255 - rgb.red[j * bih.biWidth + i];
		}
	}
}

void bmp::write(FILE* fout) {
	fwrite(&bfh.bfType, sizeof(bfh.bfType), 1, fout);
	fwrite(&bfh.bfSize, sizeof(bfh.bfSize), 1, fout);
	fwrite(&bfh.bfReserved1, sizeof(bfh.bfReserved1), 1, fout);
	fwrite(&bfh.bfReserved2, sizeof(bfh.bfReserved2), 1, fout);
	fwrite(&bfh.bfOffBits, sizeof(bfh.bfOffBits), 1, fout);

	fwrite(&bih.biSize, sizeof(bih.biSize), 1, fout);
	fwrite(&bih.biWidth, sizeof(bih.biWidth), 1, fout);
	fwrite(&bih.biHeight, sizeof(bih.biHeight), 1, fout);
	fwrite(&bih.biPlanes, sizeof(bih.biPlanes), 1, fout);
	fwrite(&bih.biBitCount, sizeof(bih.biBitCount), 1, fout);
	fwrite(&bih.biCompression, sizeof(bih.biCompression), 1, fout);
	fwrite(&bih.biSizeImage, sizeof(bih.biSizeImage), 1, fout);
	fwrite(&bih.biXPelsPerMeter, sizeof(bih.biXPelsPerMeter), 1, fout);
	fwrite(&bih.biYPelsPerMeter, sizeof(bih.biYPelsPerMeter), 1, fout);
	fwrite(&bih.biClrUsed, sizeof(bih.biClrUsed), 1, fout);
	fwrite(&bih.biClrImportant, sizeof(bih.biClrImportant), 1, fout);

	for (int j = 0; j < bih.biHeight; j++) {
		for (int i = 0; i < bih.biWidth; i++) {
			fwrite(&rgb.blue[j * bih.biWidth + i], 1, 1, fout);
			fwrite(&rgb.green[j * bih.biWidth + i], 1, 1, fout);
			fwrite(&rgb.red[j * bih.biWidth + i], 1, 1, fout);
		}
		for (int i = 0; i < bih.biWidth % 4; i++) {
			fwrite(&rgb.reserved[j * bih.biWidth % 4 + i], 1, 1, fout);
		}
	}

	free(rgb.blue);
	free(rgb.green);
	free(rgb.red);
	free(rgb.reserved);
}