#include "lab.h"
#include <stdio.h>
int main() {
	char a[] = "safd fgs sadfg";
	char b[] = "6";
	char* result = myStrpbrk(a, b, 0);
	int i = 0;
	if(result != NULL)
		while (result[i] != '\0')
			printf("%c", result[i++]);
	return 0;
}

//�������� ����������� ��������� (0 - � ������ � �����, 1 - � ����� � ������)