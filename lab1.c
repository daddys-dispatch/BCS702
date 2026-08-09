/*
 * Aim: Write a OpenMP program to sort an array on n elements using both
 * sequential and parallel mergesort(using Section). Record the difference
 * in execution time.
 */

#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r)
        temp[k++] = (a[i] <= a[j]) ? a[i++] : a[j++];

    while (i <= m)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++)
        a[i] = temp[k++];
}

void sequentialMergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;

    int m = l + (r - l) / 2;
    sequentialMergeSort(a, l, m);
    sequentialMergeSort(a, m + 1, r);
    merge(a, l, m, r);
}

void parallelMergeSort(int a[], int l, int r)
{
    if (l >= r)
        return;

    int m = l + (r - l) / 2;

#pragma omp parallel sections
    {
#pragma omp section
        parallelMergeSort(a, l, m);

#pragma omp section
        parallelMergeSort(a, m + 1, r);
    }

    merge(a, l, m, r);
}

int main(void)
{
    const int n = 100000;
    int arr1[n], arr2[n];

    for (int i = 0; i < n; i++)
        arr2[i] = (arr1[i] = rand() % 1000);

    double start = omp_get_wtime();
    sequentialMergeSort(arr1, 0, n - 1);
    printf("Sequential: %.6f s\n", omp_get_wtime() - start);

    start = omp_get_wtime();
    parallelMergeSort(arr2, 0, n - 1);
    printf("Parallel:   %.6f s\n", omp_get_wtime() - start);

    return 0;
}