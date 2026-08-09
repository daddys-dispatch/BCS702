/*
 * Aim: Write an OpenMP program that divides the Iterations into chunks containing 2
 * iterations, respectively (OMP_SCHEDULE=static,2). Its input should be the number
 * of iterations, and its output should be which iterations of a parallelized for loop
 * are executed by which thread. For example, if there are two threads and four iterations,
 * the output might be the following:
 * a. Thread 0 : Iterations 0 -- 1
 * b. Thread 1 : Iterations 2 -- 3
 */

#include <stdio.h>
#include <omp.h>

int main(void)
{
    int n;
    int start[100], end[100];

    for (int i = 0; i < 100; i++)
        start[i] = -1;

    printf("Enter number of iterations: ");
    scanf("%d", &n);

#pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < n; i++)
    {
        int tid = omp_get_thread_num();

        if (start[tid] == -1)
            start[tid] = i;

        end[tid] = i;
    }

    for (int tid = 0; tid < 100; tid++)
        if (start[tid] != -1)
            printf("Thread %d : Iterations %d -- %d\n",
                   tid, start[tid], end[tid]);

    return 0;
}