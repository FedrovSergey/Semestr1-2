#include "lab15.h"
#include <stdio.h>
#include <stdlib.h>

//переписать программу в ооп стиле (класс bmp)

int main(int argc, char** argv) {
	bmp bm;

	FILE* fin = fopen("in.bmp", "rb");
	FILE* fout = fopen("out.bmp", "wb");
	/*FILE* fin = fopen(argv[1], "rb");
	FILE* fout = fopen(argv[2], "wb");*/
	bm.read(fin);
	bm.recolor();
	bm.write(fout);
	
	fclose(fout);
	fclose(fin);
}

//BitmapFileHeader bfh;
//BITMAPINFOHEADER bih;
//RGBQuads rgb;
//
///*FILE* fin = fopen("forPractise.bmp", "rb");
//FILE* fout = fopen("out.bmp", "wb");*/
//FILE* fin = fopen(argv[1], "rb");
//FILE* fout = fopen(argv[2], "wb");
////char array[91];
////fread(array, sizeof(char), 90, fin);
////for (int i = 54; i < 91; i++) {
////	array[i] = 255 - array[i];
////}
////fwrite(array, sizeof(char), 90, fout);
//fread(&bfh.bfType, sizeof(bfh.bfType), 1, fin);
//fread(&bfh.bfSize, sizeof(bfh.bfSize), 1, fin);
//fread(&bfh.bfReserved1, sizeof(bfh.bfReserved1), 1, fin);
//fread(&bfh.bfReserved2, sizeof(bfh.bfReserved2), 1, fin);
//fread(&bfh.bfOffBits, sizeof(bfh.bfOffBits), 1, fin);
//
//fread(&bih.biSize, sizeof(bih.biSize), 1, fin);
//fread(&bih.biWidth, sizeof(bih.biWidth), 1, fin);
//fread(&bih.biHeight, sizeof(bih.biHeight), 1, fin);
//fread(&bih.biPlanes, sizeof(bih.biPlanes), 1, fin);
//fread(&bih.biBitCount, sizeof(bih.biBitCount), 1, fin);
//fread(&bih.biCompression, sizeof(bih.biCompression), 1, fin);
//fread(&bih.biSizeImage, sizeof(bih.biSizeImage), 1, fin);
//fread(&bih.biXPelsPerMeter, sizeof(bih.biXPelsPerMeter), 1, fin);
//fread(&bih.biYPelsPerMeter, sizeof(bih.biYPelsPerMeter), 1, fin);
//fread(&bih.biClrUsed, sizeof(bih.biClrUsed), 1, fin);
//fread(&bih.biClrImportant, sizeof(bih.biClrImportant), 1, fin);
//
//rgb.blue = (uint8_t*)malloc(bih.biHeight * bih.biWidth);
//rgb.green = (uint8_t*)malloc(bih.biHeight * bih.biWidth);
//rgb.red = (uint8_t*)malloc(bih.biHeight * bih.biWidth);
//rgb.reserved = (uint8_t*)malloc(bih.biHeight * bih.biWidth);
//
//for (int j = 0; j < bih.biHeight; j++) {
//	for (int i = 0; i < bih.biWidth; i++) {
//		fread(&rgb.blue[j * bih.biWidth + i], 1, 1, fin);
//		fread(&rgb.green[j * bih.biWidth + i], 1, 1, fin);
//		fread(&rgb.red[j * bih.biWidth + i], 1, 1, fin);
//	}
//	for (int i = 0; i < bih.biWidth % 4; i++) {
//		fread(&rgb.reserved[j * bih.biWidth % 4 + i], 1, 1, fin);
//	}
//}
//
//recolor(rgb, bih);
///*for (int j = 0; j < bih.biHeight; j++) {
//	for (int i = 0; i < bih.biWidth; i++) {
//		rgb.blue[j * bih.biWidth + i] = 255 - rgb.blue[j * bih.biWidth + i];
//		rgb.green[j * bih.biWidth + i] = 255 - rgb.green[j * bih.biWidth + i];
//		rgb.red[j * bih.biWidth + i] = 255 - rgb.red[j * bih.biWidth + i];
//	}
//}*/
//
//fwrite(&bfh.bfType, sizeof(bfh.bfType), 1, fout);
//fwrite(&bfh.bfSize, sizeof(bfh.bfSize), 1, fout);
//fwrite(&bfh.bfReserved1, sizeof(bfh.bfReserved1), 1, fout);
//fwrite(&bfh.bfReserved2, sizeof(bfh.bfReserved2), 1, fout);
//fwrite(&bfh.bfOffBits, sizeof(bfh.bfOffBits), 1, fout);
//
//fwrite(&bih.biSize, sizeof(bih.biSize), 1, fout);
//fwrite(&bih.biWidth, sizeof(bih.biWidth), 1, fout);
//fwrite(&bih.biHeight, sizeof(bih.biHeight), 1, fout);
//fwrite(&bih.biPlanes, sizeof(bih.biPlanes), 1, fout);
//fwrite(&bih.biBitCount, sizeof(bih.biBitCount), 1, fout);
//fwrite(&bih.biCompression, sizeof(bih.biCompression), 1, fout);
//fwrite(&bih.biSizeImage, sizeof(bih.biSizeImage), 1, fout);
//fwrite(&bih.biXPelsPerMeter, sizeof(bih.biXPelsPerMeter), 1, fout);
//fwrite(&bih.biYPelsPerMeter, sizeof(bih.biYPelsPerMeter), 1, fout);
//fwrite(&bih.biClrUsed, sizeof(bih.biClrUsed), 1, fout);
//fwrite(&bih.biClrImportant, sizeof(bih.biClrImportant), 1, fout);
//
//for (int j = 0; j < bih.biHeight; j++) {
//	for (int i = 0; i < bih.biWidth; i++) {
//		fwrite(&rgb.blue[j * bih.biWidth + i], 1, 1, fout);
//		fwrite(&rgb.green[j * bih.biWidth + i], 1, 1, fout);
//		fwrite(&rgb.red[j * bih.biWidth + i], 1, 1, fout);
//	}
//	for (int i = 0; i < bih.biWidth % 4; i++) {
//		fwrite(&rgb.reserved[j * bih.biWidth % 4 + i], 1, 1, fout);
//	}
//}
//
//free(rgb.blue);
//free(rgb.green);
//free(rgb.red);
//free(rgb.reserved);
//fclose(fout);
//fclose(fin);