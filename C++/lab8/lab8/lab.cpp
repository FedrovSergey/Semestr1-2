#include "lab.h"
//поразрядная сортировка

int getMax(int arr[], int n){
	int mx = arr[0];
	for (int i = 1; i < n; i++)
		if (arr[i] > mx)
			mx = arr[i];
	return mx;
}

void countSort(int arr[], int n, int exp){
	int* output = (int*)malloc(sizeof(int) * n); 
	int i, count[10] = { 0 };
	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = n - 1; i >= 0; i--){
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}
	for (i = 0; i < n; i++)
		arr[i] = output[i];
	free(output);
}

void radixsort(int arr[], int n){
	int m = getMax(arr, n);
	for (int exp = 1; m / exp > 0; exp *= 10)
		countSort(arr, n, exp);
}

void print(int arr[], int n){
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}
void sortArray(int* p, int* count, int size, int min) {
	for (int i = 0; i < size; i++) {
		count[p[i] - min]++;
	}
}

void printSortArray(int* count, int max, int min) {
	for (int i = 0; i < max - min + 1; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++) {
				printf("%d ", i + min);
			}
		}
	}
}


//static int size = 0, min = 0, max = 0;
//
//void getData() {
//	printf("Enter amount of numbers, min and max of numbers: ");
//	if ((scanf("%d %d %d", &size, &min, &max)) != 3) {
//		printf("error");
//		exit(0);
//	}
//	else {
//		int* p, *count;
//		p = (int*)malloc(size * sizeof(int));
//		count = (int*)malloc((max - min + 1) * sizeof(int));
//		for (int i = 0; i < max - min + 1; i++) {
//			count[i] = 0;
//		}
//		printf("Enter numbers:");
//		for (int i = 0; i < size; i++) {
//			if ((scanf(" %d", &p[i])) != 1) {
//				printf("error");
//				exit(0);
//			}
//		}
//		sortArray(p, count);
//		printSortArray(count);
//		free(p);
//	}
//}

//int maxRazr(int number) {
//	int max = 0;
//	while (number > 1) {
//		number /= 10;
//		max++;
//	}
//	return max;
//}
//
//void sortRazr(int** count, int* p, int razr, int size) {
//	int* mas, temp = 0;
//	mas = (int*)malloc(size * sizeof(int));
//	for (int i = 0; i < size; i++){
//		mas[i] = 0;
//	}
//	for (int i = 0; i < size; i++){
//		int a = valueRazr(p[i], razr);
//		count[mas[a]][a] = p[i];
//		mas[a]++;
//	}
//	for (int i = 0; i < size; i++){
//		for (int j = 0; j < mas[i]; j++){
//			p[temp] = count[j][i];
//			temp++;
//		}
//	}
//}
//
//int valueRazr(int number, int razr) {
//	while (razr > 1) {
//		number /= 10;
//		razr--;
//	}
//	return number % 10;
//}