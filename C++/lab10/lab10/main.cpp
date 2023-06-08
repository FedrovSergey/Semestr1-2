#include "lab.h"

int main() {
	FILE* f1 = fopen("file1.txt", "r");
	if (f1 == NULL) {
		printf("File open error!");
		return -1;
	}
	else {
		char* curString;
		while (feof(f1) == 0) {
			curString = getStr(f1);
			analyzeString(curString);
			curString[0] = 0;
		}
		fclose(f1);
	}
	return 0;
	//поддержание кавычек
}
//поддержка коментариев // и /**/
