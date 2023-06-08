#include "lab.h"

void takeDerivative(float* p, int size) {
	for (int i = 0; i < size; i++) {
		int h = 0, j = size - i - 1;
		while (h != (size - 1) / 2) {
			p[i] *= j;
			j--;
			h++;
		}
	}
}

void takePrimacy(float* p, int size, int k) {
	for (int i = 0; i < size; i++) {
		int h = 0, j = size - i;
		while (h != k) {
			p[i] /= j;
			j++;
			h++;
		}
	}
}

void printArray(float* p, int size) {
	for (int i = 0; i < size; i++) {
		printf("%f ", p[i]);
	}
}
