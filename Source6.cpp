//#include <iostream>
//#include <omp.h>
//
//using namespace std;
//
//void main()
//{
//	int a[100];
//
//	for (int i = 0; i < 100; i++)
//		a[i] = rand() % 200;
//
//	int sum = 0;
//	int avg1 = 0;
//	int avg2 = 0;
//
//
//#pragma omp parallel for reduction(+:sum)  // быстрое суммирование
//		for (int i = 0; i < 100; i++)
//			sum += a[i];
//
//	avg1 = sum / 100;
//
//	sum = 0;
//
//#pragma omp parallel for 
//		for (int i = 0; i < 100; i++)
//			sum += a[i];		
//
//	avg2 = sum / 100;
//
//	printf("Avg1 %d Avg2 %d", avg1, avg2);
//
//	system("pause");
//}