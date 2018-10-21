#include <iostream>
#include <omp.h>

using namespace std;

int main0()
{
	int k = 10;
	int k1 = 100;

#pragma omp parallel shared(k) private(k1)
	{
		k1 = 0;
		k1++;
		printf("%d\n", k1);

	}
	return 0;
}