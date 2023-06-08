#include "lab.h"

double random() {
	r = (double)rand() /RAND_MAX * 11;
	//if (r >= 10)r = 11;
	return r;
}

void printArray(int* arr) {
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}

void calculate(int* arr) {
	srand(18);
	for (int i = 0; i < 100000; i++) {
		random();
		for (int j = 0; j < 11; j++) {
			if (r < j + 1) {
				if (j < 10) {
					arr[j]++;
					break;
				}
				if (j == 10) { 
					arr[j - 1]++;
					break;
				}
			}
		}
	}
}
//
//void calculate() {
//	int arr[10] = { 0 };
//	srand(3);
//	for (int i = 0; i < 100000; i++) {
//		rand();
//		for (int j = 0; j < 10; j++) {
//			if (r < j + 1) {
//				arr[j]++;
//				break;
//			}
//		}
//	}
//	printArray(arr);
//}

//
//void srand(int start) {
//	r = start;
//}
//
//int rand() {
//	r = (r * 1238763 + 635241) % 1544;
//	return (r % 10);
//}


/*int l = rand();
		for (int j = 0; j < 10; j++) {
			if (l < j + 1) {
				arr[j]++;
				break;
			}
		}*/