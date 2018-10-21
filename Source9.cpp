#include <iostream>
#include <stdio.h>
#include <omp.h>
#include <time.h>

using namespace std;

void mai1322n()
{
	const int N = 10;
	const int M = 10;

	int matrix[N][M];
	int vector[M];

		for (int i = 0; i < M; i++) {
			vector[i] = i * i;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				matrix[i][j] = (i + 1) * (j + 1);
			}
		}

		int result_vector[N];
		double result_time, result_time_static, result_time_dynamic, result_time_guided, result_time_runtime;

		for (int k = 0; k < 10; ++k) {
			double start_time = omp_get_wtime();
			for (int i = 0; i < N; i++) {
				result_vector[i] = 0;
				for (int j = 0; j < M; j++) {
					result_vector[i] += matrix[i][j] * vector[j];
				}
			}
			double end_time = omp_get_wtime();
			result_time = end_time - start_time;

			omp_set_num_threads(8);
			int batch = (N * M / 8) + 1;

			double start_time_static = omp_get_wtime();

#pragma omp parallel for schedule(static, batch)
			for (int i = 0; i < N; i++) {
				result_vector[i] = 0;
				for (int j = 0; j < M; j++) {
					result_vector[i] += matrix[i][j] * vector[j];
				}
			}
			double end_time_static = omp_get_wtime();
			result_time_static = end_time_static - start_time_static;

			double start_time_dynamic = omp_get_wtime();

#pragma omp parallel for schedule(dynamic, batch)
			for (int i = 0; i < N; i++) {
				result_vector[i] = 0;
				for (int j = 0; j < M; j++) {
					result_vector[i] += matrix[i][j] * vector[j];
				}
			}
			double end_time_dynamic = omp_get_wtime();
			result_time_dynamic = end_time_dynamic - start_time_dynamic;

			double start_time_guided = omp_get_wtime();

#pragma omp parallel for schedule(guided, batch)
			for (int i = 0; i < N; i++) {
				result_vector[i] = 0;
				for (int j = 0; j < M; j++) {
					result_vector[i] += matrix[i][j] * vector[j];
				}
			}
			double end_time_guided = omp_get_wtime();
			result_time_guided = end_time_guided - start_time_guided;

			double start_time_runtime = omp_get_wtime();

#pragma omp parallel for schedule(runtime)
			for (int i = 0; i < N; i++) {
				result_vector[i] = 0;
				for (int j = 0; j < M; j++) {
					result_vector[i] += matrix[i][j] * vector[j];
				}
			}
			double end_time_runtime = omp_get_wtime();
			result_time_runtime = end_time_runtime - start_time_runtime;
		}

		printf("Time: %f\n", result_time / 10.0);
		printf("Static time: %f sec\n", result_time_static / 10.0);
		printf("Dynamic time: %f sec\n", result_time_dynamic / 10.0);
		printf("Guided time: %f sec\n", result_time_guided / 10.0);
		printf("Runtime time: %f sec\n\n", result_time_runtime / 10.0);

		system("pause");
	}


