#include <iostream>
#include <omp.h>

using namespace std;

void ma112in() {
	
	//omp_set_num_threads(8);

#pragma omp parallel num_threads(8)
	for (int i = omp_get_num_threads(); i >= 0; i--) 
	{
#pragma omp barrier //The omp barrier directive identifies a synchronization point at which threads in a parallel region will not execute beyond the omp barrier until all other threads in the team complete all explicit tasks in the region.
		if (i == omp_get_thread_num())
			printf("Hello world from %d of %d!\n", omp_get_thread_num(), omp_get_num_threads());
	}

	system("pause");
}
