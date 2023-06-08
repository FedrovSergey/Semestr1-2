#include <stdio.h>

int main() {
	int a, b, c;
	printf("write three numbers:");
	if ((scanf("%d %d %d", &a, &b, &c, "\n")) != 3) {
		printf("error");
	}
	else {
		printf("result:%d", a - c);
	}
	return 0;
}