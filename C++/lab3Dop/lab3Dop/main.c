//доп
//вывести номера в порядке возрастания элементов
#include <stdio.h>

#define N 10

int increaseIndex(int* a, int n, int* index) {
	int m = 0, minMax[2][N];
	for (int j = 0; j < n; j++) {
		minMax[0][j] = a[j];
		minMax[1][j] = j + 1;
	}
	for (int i = 0; i < n - 1; i++)	{
		for (int j = 0; j < n - i - 1; j++)	{
			if (minMax[0][j] > minMax[0][j + 1]) {
				m = minMax[0][j];
				minMax[0][j] = minMax[0][j + 1];
				minMax[0][j + 1] = m;
				m = minMax[1][j];
				minMax[1][j] = minMax[1][j + 1];
				minMax[1][j + 1] = m;
			}
		}
	}
	for (int i = 0; i < n; i++)	{
		index[i] = minMax[1][i];
	}
	return index;
}

int main() {
	int array[N], index[N] = { 0 };
	printf("Enter array of numbers:");
	for (int i = 0; i < N; i++) {
		if (scanf("%d", &array[i]) != 1) {
			printf("error, enter only numbers next time");
			goto flag;
		}
	}
	printf("\nResult:");
	increaseIndex(array, N, index);
	for (int i = 0; i < N; i++){
		printf("%d ", index[i]);
	}
flag:;
	return 0;
}