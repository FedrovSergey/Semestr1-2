#include <stdio.h>

int minMax(int* index, char* s, int g) {
	int i = 0, j = 0, k = 0, m;
	for (j = 0; j < g - 1; j++) {
		for (i = 0; i < g - j - 1; i++) {
			if (s[index[i] + 1] > s[index[i + 1] + 1]) {
				m = index[i];
				index[i] = index[i + 1];
				index[i + 1] = m;
			}
			else if (s[index[i] + 1] == s[index[i + 1] + 1]) {
				k = 2;
				while (s[index[i] + k] != ' ') {
					if (s[index[i] + k] > s[index[i + 1] + k]) {
						m = index[i];
						index[i] = index[i + 1];
						index[i + 1] = m;
						break;
					}
					else if (s[index[i] + k] == s[index[i + 1] + k]) k++;
					else break;
				}
			}
		}
	}
	return index;
}
int main() {
	char string[1001], endString[1001] = { 0 };
	printf("Enter string:");
	fgets(string, 1000, stdin);
	'\n';
	int k = 0, j = 0, g = 0, index[100];
	index[g] = -1;
	g++;
	k = 0;
	while (string[k] != '\0') {
		if (string[k] == ' ') {
			index[g] = k;
			g++;
		}
		k++;
	}
	minMax(index, string, g);
	for (int i = 0; i < g; i++)	{
		printf("%d ", index[i]);
	}
	int l = 0, z = 0;
	for (int i = 0; i < g; i++)	{
		z = 1;
		while (string[index[i] + z] != ' ' && string[index[i] + z] != '\0') {
			endString[l] = string[index[i] + z];
			l++;
			z++;
		}
		endString[l] = ' ';
		l++;
	}
	endString[l] = '\0';
	l++;
	for (int i = 0; i < l; i++)	{
		printf("%c", endString[i]);
	}
    return 0;
}