#include "lab16.h"
#include <stdio.h>
#include <stdlib.h>
// передается в качестве параметра номер секунды, с этой секунды в файле начинается тишина

int main(int argc, char** argv) {
	FILE* fin = fopen("try.wav", "rb");
	FILE* fout = fopen("try1.wav", "wb");
	/*FILE* fin = fopen(argv[1], "rb");
	FILE* fout = fopen(argv[2], "wb");*/
	WAVEHEADER wh;
	uint8_t *data;
	fread(&wh.RIFF, sizeof(wh.RIFF), 1, fin);
	fread(&wh.ChunkSize, sizeof(wh.ChunkSize), 1, fin);
	fread(&wh.WAVE, sizeof(wh.WAVE), 1, fin);
	fread(&wh.fmt, sizeof(wh.fmt), 1, fin);
	fread(&wh.Subchunk1Size, sizeof(wh.Subchunk1Size), 1, fin);
	fread(&wh.AudioFormat, sizeof(wh.AudioFormat), 1, fin);
	fread(&wh.NumOfChan, sizeof(wh.NumOfChan), 1, fin);
	fread(&wh.SamplesPerSec, sizeof(wh.SamplesPerSec), 1, fin);
	fread(&wh.bytesPerSec, sizeof(wh.bytesPerSec), 1, fin);
	fread(&wh.blockAlign, sizeof(wh.blockAlign), 1, fin);
	fread(&wh.bitsPerSample, sizeof(wh.bitsPerSample), 1, fin);
	fread(&wh.dataH, sizeof(wh.dataH), 1, fin);
	fread(&wh.dataSize, sizeof(wh.dataSize), 1, fin);
	data = (uint8_t*)malloc(wh.dataSize);
	fread(data, 1, wh.dataSize, fin);

	/*printf("%d ", wh.ChunkSize);
	printf("%d ", wh.Subchunk1Size);
	printf("%d ", wh.AudioFormat);
	printf("%d ", wh.NumOfChan);
	printf("%d ", wh.SamplesPerSec);
	printf("%d ", wh.bytesPerSec);
	printf("%d ", wh.blockAlign);
	printf("%d ", wh.bitsPerSample);
	printf("%d ", wh.dataSize);*/
	
	/*wh.ChunkSize = wh.ChunkSize * 4 - 12;
	wh.dataSize = wh.dataSize * 4;
	
	d = (_int16*)malloc(wh.dataSize);
	for (int i = 0; i < wh.dataSize /2; i++){
		d[i] = (data[i / 2] - 128) * 256;
	}
	wh.bitsPerSample = 16;
	wh.blockAlign = wh.NumOfChan* wh.bitsPerSample / 8;
	wh.SamplesPerSec *= 2;
	wh.bytesPerSec = wh.SamplesPerSec * wh.NumOfChan * wh.bitsPerSample / 8;*/

	_int16* d = convert(data, &wh);
	//_int8* d = makeSilence(data, &wh, atoi(argv[3]));

	/*printf("\n%d ", wh.ChunkSize);
	printf("%d ", wh.Subchunk1Size);
	printf("%d ", wh.AudioFormat);
	printf("%d ", wh.NumOfChan);
	printf("%d ", wh.SamplesPerSec);
	printf("%d ", wh.bytesPerSec);
	printf("%d ", wh.blockAlign);
	printf("%d ", wh.bitsPerSample);
	printf("%d ", wh.dataSize);*/

	fwrite(&wh.RIFF, sizeof(wh.RIFF), 1, fout);
	fwrite(&wh.ChunkSize, sizeof(wh.ChunkSize), 1, fout);
	fwrite(&wh.WAVE, sizeof(wh.WAVE), 1, fout);
	fwrite(&wh.fmt, sizeof(wh.fmt), 1, fout);
	fwrite(&wh.Subchunk1Size, sizeof(wh.Subchunk1Size), 1, fout);
	fwrite(&wh.AudioFormat, sizeof(wh.AudioFormat), 1, fout);
	fwrite(&wh.NumOfChan, sizeof(wh.NumOfChan), 1, fout);
	fwrite(&wh.SamplesPerSec, sizeof(wh.SamplesPerSec), 1, fout);
	fwrite(&wh.bytesPerSec, sizeof(wh.bytesPerSec), 1, fout);
	fwrite(&wh.blockAlign, sizeof(wh.blockAlign), 1, fout);
	fwrite(&wh.bitsPerSample, sizeof(wh.bitsPerSample), 1, fout);
	fwrite(&wh.dataH, sizeof(wh.dataH), 1, fout);
	fwrite(&wh.dataSize, sizeof(wh.dataSize), 1, fout);
	fwrite(d, 1, wh.dataSize, fout);
	fclose(fin);
	fclose(fout);
	return 0;
}