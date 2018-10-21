#include <iostream>
#include <omp.h>

using namespace std;

void mai12n()
{
	int a[12], b[12], c[12];

	omp_set_num_threads(3);

#pragma omp for schedule(static, 3)
		for (int i = 0; i < 12; i++)
		{
			a[i] = i + 1;
			b[i] = i + 2;

			printf("MasA %d, MasB %d", a[i], b[i]);
		}


	printf("Col %d Num %d ", omp_get_num_threads(), omp_get_thread_num());

	omp_set_num_threads(4);

#pragma omp for schedule(dynamic, 3)
		for (int i = 0; i < 12; i++)
		{
			c[i] = a[i] + b[i];
			printf("MasC %d", c[i]);
		}


	printf("Col %d Num %d ", omp_get_num_threads(), omp_get_thread_num());


}