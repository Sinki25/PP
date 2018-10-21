#include <iostream>
#include <omp.h>

using namespace std;

void ma221in()
{
	int num1 = 3;
	omp_set_num_threads(num1);
	
	#pragma omp parallel if(num1 >2 )
	{
		int rank = omp_get_thread_num();
		int num = omp_get_num_threads();
		printf("%d %d\n", rank, num);
	}

	num1 = 1;
	omp_set_num_threads(num1);

#pragma omp parallel if(num1 >2 )
	{
		int rank = omp_get_thread_num();
		int num = omp_get_num_threads();
		printf(" Error %d %d\n", rank, num);
	}

	system("pause");
		
}