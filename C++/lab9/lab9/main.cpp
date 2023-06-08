#include "lab.h"
//написать функцию, которая берёт k-ую первообразную, k вводим сами

int main() {
	int size, k;
	printf("Enter size of polinomial:");
	if (scanf("%d", &size) != 1) {
		printf("error");
		exit;
	}
	else {
		size++;
		float* p;
		p = (float*)malloc(size * sizeof(float));
		printf("Enter coefficients of polynomial:");
		for (int i = 0; i < size; i++) {
			if (scanf("%f", &p[i]) != 1) {
				printf("error");
				exit;
			}
		}
		printf("Enter degree of taking primacy:");
		if (scanf("%d", &k) != 1) {
			printf("error");
			exit;
		}  
		/*takeDerivative(p, size);*/
		takePrimacy(p, size, k);
		printArray(p, size);
		free(p);
	}
	return 0;
}