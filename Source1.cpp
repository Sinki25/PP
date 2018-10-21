#include <iostream>
#include <omp.h>
#define N 100// меняет N на 100

using namespace std;

void main2()
{
#pragma omp parallel num_threads(8)
	{
		int rank = omp_get_thread_num();
		int num = omp_get_num_threads();
		printf("Hello, world %d %d\n",rank, num);
	}

	system("pause");

}