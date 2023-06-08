#include <stdio.h>

#define N 10

int result[100], k = 0;

void differ(int* a, int n) {
	int iMax[10], iMin[10], max = a[0], min = a[0], numberMax = 0, numberMin = 0;
	for (int j = 0; j < n; j++) {
		if (max == a[j]) {
			iMax[numberMax] = j;
			numberMax++;
			max = a[j];
		}
		else if (max < a[j]) {
			for (int i = 0; i < numberMax; i++)	{
				iMax[i] = 0;
			}
			numberMax = 1;
			iMax[0] = j;
			max = a[j];
		}
		else if (min == a[j]) {
			iMin[numberMin] = j;
			numberMin++;
			min = a[j];
		}
		else if (min > a[j]) {
			for (int i = 0; i < numberMin; i++) {
				iMin[i] = 0;
			}
			numberMin = 1;
			iMin[0] = j;
			min = a[j];
		}
	}
	if (numberMax != 10) {
		printf("Result:");
		for (int i = 0; i < numberMax; i++) {
			for (int j = 0; j < numberMin; j++) {
				for (int f = 0; f < k; f++) {
					if (iMax[i] - iMin[j] == result[f]) {
						goto flag;
					}
				}
				result[k] = iMax[i] - iMin[j];
				k++;
			flag:;
			}
		}
	}
}
int main() {
	int array[N];
	printf("Enter array of numbers:");
	for (int i = 0; i < N; i++)	{
		scanf("%d", &array[i]);
	}
	'\n';
	differ(array, N);
	if (k == 0) {
		printf("Result: 0");
	}
	else {
		printf("Result: ");
		for (int i = 0; i < k; i++)	{
			printf("%d ", result[k]);
		}
	}
	return 0;
}
//переделать вывод (через return), проверка на буквы
//доп
//вывести индексы в порядке возрастания элементов