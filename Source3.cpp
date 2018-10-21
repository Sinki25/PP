#include <iostream>
#include <omp.h>

using namespace std;

void ma22in()
{
	int a = 5;
	int b = 6;
	
	printf("Before %d %d\n",a,b);

#pragma omp parallel num_threads(2) private(a) firstprivate(b) // private только внутри параллельной области , firstprivate первое значение до параллельной области, т.к. сущ до параллельной области
	{
		int rank = omp_get_thread_num();
		a = 5;
	//	b = 6;

		a += rank;
		b += rank;
		printf(" %d %d %d\n",a,b,rank);
	}

	printf("After %d %d\n",a,b);

#pragma omp parallel num_threads(4) shared(a) private(b)
	{
	//	a = 5;
		b = 6;

		a -= omp_get_thread_num();
		b -= omp_get_thread_num();
		printf(" %d %d %d\n", a, b, omp_get_thread_num());
	}

	printf("After %d %d\n", a, b);

	system("pause");

}