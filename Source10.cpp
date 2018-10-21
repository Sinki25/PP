#include <stdio.h>
#include <time.h>
#include <iostream>
#include <omp.h>
#include <stdlib.h>

using namespace std;


void m222ain() {

    srand(time(NULL)); // устанавливает в качестве базы текущее время
    int d[6][8];

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            d[i][j] = rand() % 10;
            printf("%d, ", d[i][j]);
        }
        printf("\n");
    }

    int min =10;
    int max =0;

#pragma omp parallel for
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            if (d[i][j] < min) {
#pragma omp critical(minSection) //Этот тип синхронизации используется для описания структурных блоков, выполняющихся только в одном потоке из всего набора параллельных потоков.
                {
                    if (d[i][j] < min)
                        min = d[i][j];
                }
            }

            if (d[i][j] > max) {
#pragma omp critical(maxSection) //  Несколько потоков будут пытаться одновременно обращаться к переменной sum для чтения и записи.
                {
                    if (d[i][j] > max)
                        max = d[i][j];
                }
            }
        }
    }
    printf("Min: %d, Max: %d\n", min, max);

	//printf("%d", omp_get_max_threads());
    int minRedArr[4];
    int maxRedArr[4];

    for (int k = 0; k < omp_get_num_threads(); ++k) {
        minRedArr[k] = 10;
        maxRedArr[k] =0;
    }

#pragma omp parallel for schedule(runtime)
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            if (d[i][j] < minRedArr[omp_get_thread_num()])
                minRedArr[omp_get_thread_num()] = d[i][j];

            if (d[i][j] > maxRedArr[omp_get_thread_num()])
                maxRedArr[omp_get_thread_num()] = d[i][j];
        }
    }

    int minRed = minRedArr[0];
    int maxRed = maxRedArr[0];
    for (int l = 1; l < omp_get_max_threads(); ++l) {
        if (minRedArr[l] < minRed)
            minRed = minRedArr[l];

        if (maxRedArr[l] > maxRed)
            maxRed = maxRedArr[l];
    }
    printf("Reduction. Min: %d, Max: %d\n", minRed, maxRed);

	system("pause");
}