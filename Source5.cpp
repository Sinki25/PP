#include <iostream>
#include <omp.h>

using namespace std;

void ma11in() 
{
	int a[6][8];

	for (int i = 0; i < 6; i++)
		for (int j = 0; j < 8; j++)
		{
			a[i][j] = rand() %100;
			printf("%d ", a[i][j]);
		}

#pragma omp parallel sections
	{
#pragma omp section
		{
			int avg=0;
			int sum = 0;


			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 8; j++)
				{
					sum += a[i][j];
				}

			avg = sum / 48;

			printf("Average %d ", avg);
			
		}

#pragma omp section
		{
			int max = 0;
			int min = 100;


			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 8; j++)
				{
					if (a[i][j] > max)
						max = a[i][j];
					if (a[i][j] < min)
						min = a[i][j];
				}


			printf("Max %d Min %d", max, min);

		}

#pragma omp section
		{
			int num = 0;
			

			for (int i = 0; i < 6; i++)
				for (int j = 0; j < 8; j++)
				{
					if (a[i][j] % 3 == 0)
						num += 1;
				}


			printf("Col %d ", num);

		}
	}


	system("pause");
}