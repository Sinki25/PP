#include <stdio.h>
//#include <time.h>
#include <iostream>
#include <omp.h>
#include <stdlib.h>

using namespace std;

void mainqw() {

	omp_set_num_threads(8);

	int a[30];

	for (int i = 0; i < 30; i++) {
		a[i] = rand() % 30;
		printf("%d ", a[i]);
	}
	printf("\n");

	int count = 0;

#pragma omp parallel for
	for (int i = 0; i < 30; i++) {
		if (a[i] % 9 == 0) {
			printf("%d\n", a[i]);
#pragma omp atomic // На время выполнения оператора блокируется доступ к данной переменной всем запущенным в данный момент потокам, кроме потока, выполняющей операцию. 
			count++;
		}
	}

	printf("Count: %d", count);
	system("pause");
}