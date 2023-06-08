#include <stdio.h>

//заменить табы на пробелы
//доп
//не выводить одинаковые слова (выводить только 1)

int main() {
	char string[1000], endString[1000] = "", string1[100][1000];
	printf("write string (<1000 symbols):");
	fgets(string, 1000, stdin);
	int i = 0, k = 0;
	while (string[i + 1] != '\0') {
		i++;
	}
	for (int z = i; z > -1; z--) {
		if ((string[z] == ' ') || (string[z] == '\t')) {
			for (int j = z + 1; j <= i; j++) {
				if (string[j] != '\t') {
					endString[k] += string[j];
					k++;
				}
				else if ((string[j] == '\t') && (endString[k - 1] != ' ')) {
					endString[k] += ' ';
					k++;
				}
			}
			i = z;
		}
		else if (z == 0) {
			for (int j = z; j <= i; j++) {
				endString[k] += string[j];
				k++;
			}
		}
	}
	int j = 0;
	for (int i = 0; i < k; i++)	{
		int h = 0;
		while (endString[i] != ' ') {
			string1[j][h] = endString[i];
			h++;
			i++;
		}
		string1[j][h] = ' ';
		j++;
	}
	int h = 0, l = 0;
	for (int n = 0; n < j; n++)	{
		for (int g = 0; g < n; g++)	{
			h = 0, l = 0;
			while ((string1[g][h] != ' ') && (string1[n][h] != ' ')) {
				if (string1[n][h] != string1[g][h]) {
					goto flag;
				}
				else {
					l++;
				}
				h++;
			}
			if (h == l) {
				for (int f = 0; f < h; f++)	{
					string1[n][f] = ' ';
				}
				goto flag1;
			}
		flag:;
		}
	flag1:;
	}
	printf("result:");
	for (int p = 0; p < j; p++)	{
		int d = 0;
		while (string1[p][d] != ' ') {
			printf("%c", string1[p][d]);
			d++;
		}
		printf(" ");
	}
	return 0;
}
