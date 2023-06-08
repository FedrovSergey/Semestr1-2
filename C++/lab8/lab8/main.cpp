#include "lab.h"


int main() {
	int size = 0;
	printf("Enter amount of numbers:");
	if ((scanf("%d", &size)) != 1) {
		printf("error");
		exit(0);
	}
	else {
		int* p;
		p = (int*)malloc(size * sizeof(int));
		printf("Enter numbers:");
		for (int i = 0; i < size; i++) {
			if ((scanf(" %d", &p[i])) != 1) {
				printf("error");
				exit(0);
			}
		}
		radixsort(p, size);
		print(p, size);
	}
	return 0;
}

//int main() {
//	/*int size = 0, min = 0, max = 0;
//	printf("Enter amount of numbers, min and max of numbers:");
//	if ((scanf("%d %d %d", &size, &min, &max)) != 3) {
//		printf("error");
//		exit(0);
//	}
//	else {
//		int* p, * count;
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
//			if (p[i] < min || p[i] > max) {
//				printf("Your number < min number or > max number");
//				exit(0);
//			}
//		}
//		sortArray(p, count, size, min);
//		printSortArray(count, max, min);
//		free(p);
//	}*/
//	return 0;
//}