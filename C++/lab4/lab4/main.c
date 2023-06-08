#include <stdio.h>

int main() {
	char string[1000], words[100][1000];
	printf("Enter string:");
	fgets(string, 1000, stdin);
	int i = 0;
	while (*string != '\0') {
		i++;
	}
	int j = 0;
	for (int z = 0; z < i; z++) {
		int h = 0;
		while ((string[z] != ' ') && (z != i)) {
			words[j][h] = string[z];
			h++;
			z++;
		}
		words[j][h] = ' ';
		j++;
	}
	for (int i = 0; i < j; i++)	{
		int z = 0, h = 0;
		while (words[i][z] != ' ') {
			while (words[i][h] != ' ') {
				if (z == h)h++;
				if ((words[i][z] != words[i][h]) && (words[i][h + 1] == ' ')) {
					goto next;
				}
				else if((words[i][h] == ' ') || (words[i][h] == words[i][z])){
					goto flag;
				}
				h++;
			}
		flag:;
			z++;
			h = 0;
		}
		z = 0;
		while (words[i][z] != ' ') {
			printf("%c", words[i][z]);
			z++;
		}
		printf(" ");
	next:;
	}
	return 0;
}