#include "lab.h"
#include <stdio.h>

char* myStrpbrk(const char* string, const char* strCharSet, int a) {
	int i = 0, j = 0;
	if (a == 0) {
		while (string[i] != '\0') {
			j = 0;
			while (strCharSet[j] != '\0') {
				if (string[i] == strCharSet[j])return (char*)&string[i];
				j++;
			}
			i++;
		}
	}
	else if(a == 1) {
		while (string[i + 1] != '\0') {
			i++;
		}
		while (i >= 0) {
			j = 0;
			while (strCharSet[j] != '\0') {
				if (string[i] == strCharSet[j])return (char*)&string[i];
				j++;
			}
			i--;
		}
	}
	return NULL;
}