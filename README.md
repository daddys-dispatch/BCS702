# BCS702 - Parallel Computing Lab

> **Note:** All the codes in this repo were written by pookie himself and nobody questions him. 👑

---

## 🚀 Cloning the Repository

Clone the repository and enter the directory:

```bash
git clone https://github.com/daddys-dispatch/BCS702
cd BCS702
```

---

## 🏃 How to Run the Programs

### 1. OpenMP Programs (Lab 1 to Lab 4)

Compile using `gcc` with `-fopenmp` and execute:

```bash
# Example: Compiling and running Lab 1
gcc -fopenmp lab1.c -o lab1
./lab1

# Example: Compiling and running Lab 2
gcc -fopenmp lab2.c -o lab2
./lab2
```

---

### 2. MPI Programs (Lab 5 to Lab 9)

Compile using `mpicc` and execute using `mpirun` or `mpiexec` specifying the process count (`-np`):

```bash
# Example: Compiling and running Lab 5 with 2 processes
mpicc lab5.c -o lab5
mpirun -np 2 ./lab5

# Example: Compiling and running Lab 9 with 4 processes
mpicc lab9.c -o lab9
mpirun -np 4 ./lab9
```

---

## 📑 Lab List

- **Lab 1**: OpenMP MergeSort (Sequential vs. Parallel using `sections`).
- **Lab 2**: OpenMP static iteration chunk scheduling (`schedule(static, 2)`).
- **Lab 3**: OpenMP Fibonacci series calculation using `tasks`.
- **Lab 4**: OpenMP Prime numbers using parallel `for` loop.
- **Lab 5**: MPI Point-to-Point Communication (`MPI_Send` and `MPI_Recv`).
- **Lab 6**: MPI Deadlock Demonstration and Avoidance.
- **Lab 7**: MPI Broadcast operation (`MPI_Bcast`).
- **Lab 8**: MPI Scatter and Gather (`MPI_Scatter` and `MPI_Gather`).
- **Lab 9**: MPI Reduction operations (`MPI_Reduce` and `MPI_Allreduce`).
