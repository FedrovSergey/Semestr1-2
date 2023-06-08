#include<stdio.h>
#include<stdlib.h>
//etc. = et cetera
//e.g. = exempli gratia
//i.e. = id est
//h.e. = hoc est
int countWords(char* s) {
	int g = 0, number = 0, i = 0;
	while (s[i] != '\0') {
		if (s[i] != ' ')
			g = 1;
		else {
			if (g == 1) {
				number++;
			}
			g = 0;
		}
		i++;
	}
	if (g == 1)
		number++;
	return number;
}

void copyWord(char* dst, char* src, int start, int end) {
	int j = 0, k = 0;
	for (j = start; j < end; j++) {
		dst[k] = src[j];
		k++;
	}
	dst[k] = '\0';
}

int myLength(char* s) {
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}
int replace(char* s) {
	if (s[3] == '.') {
		if (s[0] == 'e' && s[1] == 't' && s[2] == 'c')return 0;
		else if (s[0] == 'e' && s[1] == '.' && s[2] == 'g')return 1;
		else if (s[0] == 'i' && s[1] == '.' && s[2] == 'e')return 2;
		else if (s[0] == 'h' && s[1] == '.' && s[2] == 'e')return 3;
	}
	return 4;
}

int main() {
	char string[1001] = "";
	char** words;
	char replacement[4][16] = { "et cetera \0",
							"exempli gratia \0",
							"id est \0",
							"hoc est \0" };
	int i = 0;
	printf("Enter string:");
	fgets(string, 1000, stdin);
	'\n';
	int d = countWords(string);
	words = (char**)malloc(sizeof(char*) * d * 2);
	int wordCount = 0, start = 0, end = 0, in = 0, startH = 0, endH = 0, inH = 0;
	while (string[i] != '\0') {
		if (string[i] != ' ' && string[i + 1] != '\0') {
			if (in == 0)
				start = i;
			in = 1;
		}
		else {
			if (in == 1) {
				end = i;
				words[wordCount] = (char*)malloc(end - start + 1);
				copyWord(words[wordCount], string, start, end);
				if (myLength(words[wordCount]) == 4) {
					int index = replace(words[wordCount]);
					if (index < 4) {
						free(words[wordCount]);
						int f = 0, l = 0;
						while (replacement[index][f] != '\0') {
							if (replacement[index][f] != ' ' && replacement[index][f + 1] != '\0') {
								if (inH == 0)
									startH = f;
								inH = 1;
							}
							else {
								if (inH == 1) {
									l++;
									endH = f;
									words[wordCount] = (char*)malloc(endH - startH + 1);
									copyWord(words[wordCount], replacement[index], startH, endH);
									if(l < 2) wordCount++;
								}
								inH = 0;
							}
							f++;
						}
					}
				}
				wordCount++;
			}
			in = 0;
		}
		i++;
	}
	char** endString;
	int number = (wordCount) / 4;
	int h = 0;
	if ((wordCount) % 4 != 0) {
		number++;
	}
	endString = (char**)malloc(sizeof(char*) * number);
	int numberOfSpace = 0, dopSpace = 0;
	for (int i = 0; i < number; i++){
		endString[i] = (char*)malloc(61);
		int numberOfLetters = 0;
		int l = i * 4, k = (i + 1) * 4;
		for (int z = l; z < k; z++){
			if(z < wordCount)
			numberOfLetters += myLength(words[z]);
			else numberOfLetters += myLength(words[wordCount - 1]);
		}
		numberOfSpace = (55 - numberOfLetters) / 3;
		dopSpace = (55 - numberOfLetters) % 3;
		int amountOfSpace = 0;
		for (int j = 0; j < 60; j++){
			if (j < 5)endString[i][j] = ' ';
			else {
				int g = 0;
				if (h < wordCount) {
					while (words[h][g] != '\0') {
						endString[i][j] = words[h][g];
						j++;
						g++;
					}
					h++;
					if (amountOfSpace < 3) {
						for (int l = 0; l < numberOfSpace; l++) {
							endString[i][j] = ' ';
							j++;
						}
						j--;
						if (amountOfSpace == 2) {
							for (int l = 0; l < dopSpace + 1; l++) {
								endString[i][j] = ' ';
								j++;
							}
							j--;
						}
						amountOfSpace++;
					}
				}
				else {
					while (words[wordCount - 1][g] != '\0') {
						endString[i][j] = words[wordCount - 1][g];
						j++;
						g++;
					}
					h++;
					if (amountOfSpace < 3) {
						for (int l = 0; l < numberOfSpace; l++) {
							endString[i][j] = ' ';
							j++;
						}
						j--;
						if (amountOfSpace == 2) {
							for (int l = 0; l < dopSpace + 1; l++) {
								endString[i][j] = ' ';
								j++;
							}
							j--;
						}
						amountOfSpace++;
					}
				}
			}
		}
		endString[i][60] = '\0';
	}
	for (int y = 0; y < number; y++) {
		for (int z = 0; z < 61; z++) {
			if(endString[y][z] != '\0')
			printf("%c", endString[y][z]);
		}
		printf("\n");
	}
	int r = 0;
	for (r = 0; r < wordCount; r++)
		free(words[r]);
	for (r = 0; r < number; r++)
		free(endString[r]);
	return 0;
}
//доп
//6 вариант