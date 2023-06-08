#pragma once
#include <stdint.h>

typedef struct {
    /* RIFF Chunk Descriptor */
    uint8_t RIFF[4];        // RIFF Header Magic header
    uint32_t ChunkSize;      // RIFF Chunk Size
    uint8_t WAVE[4];        // WAVE Header
    /* "fmt" sub-chunk */
    uint8_t fmt[4];         // FMT header
    uint32_t Subchunk1Size;  // Size of the fmt chunk
    uint16_t AudioFormat;    // Audio format 1=PCM
    uint16_t NumOfChan;      // Number of channels 1=Mono 2=Sterio
    uint32_t SamplesPerSec;  // Sampling Frequency in Hz
    uint32_t bytesPerSec;    // bytes per second
    uint16_t blockAlign;     // 2=16-bit mono, 4=16-bit stereo
    uint16_t bitsPerSample;  // Number of bits per sample
    uint8_t dataH[4];  //data header
    uint32_t dataSize;
}WAVEHEADER;

_int16* convert(uint8_t* data, WAVEHEADER* wh);
_int8* makeSilence(uint8_t* data, WAVEHEADER* wh, int sec);