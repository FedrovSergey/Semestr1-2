#include "lab16.h"
#include <stdio.h>
#include <stdlib.h>

_int16* convert(uint8_t* data, WAVEHEADER* wh) {
	wh->ChunkSize = wh->ChunkSize * 4 - 12;
	wh->dataSize = wh->dataSize * 4;
	_int16* d = (_int16*)malloc(wh->dataSize);
	for (int i = 0; i < wh->dataSize / 2; i++) {
		d[i] = (data[i / 2] - 128) * 256;
	}
	wh->bitsPerSample = 16;
	wh->blockAlign = wh->NumOfChan * wh->bitsPerSample / 8;
	wh->SamplesPerSec *= 2;
	wh->bytesPerSec = wh->SamplesPerSec * wh->NumOfChan * wh->bitsPerSample / 8;
	return d;
}

_int8* makeSilence(uint8_t* data, WAVEHEADER* wh, int sec) {
	_int8* d = (_int8*)malloc(wh->dataSize);
	printf("%d", sec);
	for (int i = 0; i < sec * wh->bytesPerSec; i++) {
		d[i] = data[i];
	}
	for (int i = sec * wh->bytesPerSec; i < wh->dataSize; i++) {
		d[i] = 0;
	}
	return d;
}

/*wh1.RIFF[0] = 'R'; wh1.RIFF[1] = 'I'; wh1.RIFF[2] = 'F'; wh1.RIFF[3] = 'F';
	wh1.ChunkSize = wh.ChunkSize * 4 - 12;
	wh1.WAVE[0] = 'W'; wh1.WAVE[1] = 'A'; wh1.WAVE[2] = 'A'; wh1.WAVE[3] = 'E';
	wh1.fmt[0] = wh.fmt[0]; wh1.fmt[1] = wh.fmt[1]; wh1.fmt[2] = wh.fmt[2]; wh1.fmt[3] = wh.fmt[3];
	wh1.Subchunk1Size = wh.Subchunk1Size;
	wh1.AudioFormat = wh.AudioFormat;
	wh1.NumOfChan = wh.NumOfChan;
	wh1.SamplesPerSec = wh.SamplesPerSec * 2;
	wh1.bitsPerSample = 16;
	wh1.dataSize = wh.dataSize * 4;
	wh1.dataH[0] = 'd'; wh1.dataH[1] = 'a'; wh1.dataH[2] = 't'; wh1.dataH[3] = 'a';
	wh1.data = (_int16*)malloc(wh1.dataSize);
	for (int i = 0; i < wh1.dataSize / 2; i++) {
		wh1.data[i] = (data[i / 2] - 128) * 256;
	}
	wh1.blockAlign = wh1.NumOfChan * wh1.bitsPerSample / 8;
	wh1.bytesPerSec = wh1.SamplesPerSec * wh1.NumOfChan * wh1.bitsPerSample / 8;*/