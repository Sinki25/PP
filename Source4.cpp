#include <iostream>
#include <omp.h>

using namespace std;

void main13()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int b[10] = { 1,3,5,4,8,6,7,2,9,0 };

	int min = 10;
	int max = 0;


#pragma omp parallel num_threads(2) 
	{
		if (omp_get_thread_num() == 0)
		{
			for (int i = 0; i < 10; i++)
			{
				if (a[i] < min)
					min = a[i];
			}
		}

		if (omp_get_thread_num() == 1)
		{
			for (int i = 0; i < 10; i++)
			{
				if (b[i] > max)
					max = b[i];
			}
		}
		printf(" %d %d \n", min, max);
	}

	system("pause");
}