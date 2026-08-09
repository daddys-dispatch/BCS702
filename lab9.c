/*
 * Aim: Write a MPI Program to demonstration of MPI_Reduce and MPI_Allreduce
 * (MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD).
 */

#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    int rank, value;
    int sum, prod, max, min;
    int all_sum, all_prod, all_max, all_min;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    value = rank + 1;

    MPI_Reduce(&value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&value, &prod, 1, MPI_INT, MPI_PROD, 0, MPI_COMM_WORLD);
    MPI_Reduce(&value, &max, 1, MPI_INT, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&value, &min, 1, MPI_INT, MPI_MIN, 0, MPI_COMM_WORLD);

    MPI_Allreduce(&value, &all_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);
    MPI_Allreduce(&value, &all_prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);
    MPI_Allreduce(&value, &all_max, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);
    MPI_Allreduce(&value, &all_min, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("MPI_Reduce Results:\n");
        printf("Sum = %d\nProduct = %d\nMax = %d\nMin = %d\n",
               sum, prod, max, min);
    }

    printf("Process %d: value=%d | Sum=%d Prod=%d Max=%d Min=%d\n",
           rank, value, all_sum, all_prod, all_max, all_min);

    MPI_Finalize();
    return 0;
}