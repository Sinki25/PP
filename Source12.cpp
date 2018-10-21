#include <stdio.h>
//#include <time.h>
#include <iostream>
#include <omp.h>
#include <stdlib.h>

using namespace std;

void ma21in() {
	//srand(time(NULL));
	int a[10];

	for (int i = 0; i < 10; i++) {
		a[i] = rand() % 30;
		printf("%d ", a[i]);
	}
	printf("\n");

	int max = 0;

#pragma omp parallel for
	for (int i = 0; i < 10; i++) {
		if (a[i] % 7 == 0 && a[i] > max) {
#pragma omp critical
			if (a[i] > max) {
				max = a[i];
			}
		}
	}

	printf("Max: %d", max);
	system("pause");
}