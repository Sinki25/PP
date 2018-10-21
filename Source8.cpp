#include <iostream>
#include <omp.h>

using namespace std;

void main()
{
	const int n = 16000;
	int a[n], b[n-2];
	
	for (int i = 0; i < n; i++)
		a[i] = i;

	omp_set_num_threads(8);

	double result_time;

	double start_time = omp_get_wtime();

#pragma omp for schedule(static, 3) // �������� �������������� ����������
	for (int i = 1; i <n-1; i++)
	{
		b[i] = (a[i-1] + a[i] + a[i+1])/3.0;
		
	}

	double end_time = omp_get_wtime();
	result_time = end_time - start_time;

	printf("Time1 %f \n", result_time);

	 start_time = omp_get_wtime();

#pragma omp for schedule(dynamic, 160) // �������������� ����� ��������, ��������� �������
	for (int i = 1; i <n - 1; i++)
	{
		b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
		
	}

	 end_time = omp_get_wtime();
	result_time = end_time - start_time;

	printf("Time1 %f \n", result_time);

	 start_time = omp_get_wtime();

#pragma omp for schedule(guided, 100) // ������ ����� ����������� �� ���������� ��������
	for (int i = 1; i <n - 1; i++)
	{
		b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
		
	}

	 end_time = omp_get_wtime();
	result_time = end_time - start_time;

	printf("Time1 %f \n", result_time);

	 start_time = omp_get_wtime();

#pragma omp for schedule(runtime) // ��� ������������� ��� �� ����� ������
	for (int i = 1; i <n - 1; i++)
	{
		b[i] = (a[i - 1] + a[i] + a[i + 1]) / 3.0;
		
	}

	end_time = omp_get_wtime();
	result_time = end_time - start_time;

	printf("Time1 %f \n", result_time);

	system("pause");
}