// Write an MPI program to calculate sum of all odd randomly generated 1000 numbers
// (stored in array) on a cluster
// Slip 22, 24, 

// #include <stdio.h>
// #include <stdlib.h>
// #include <mpi.h>

// #define ARRAY_SIZE 1000

// int main(int argc, char** argv) {
//     MPI_Init(&argc, &argv);

//     int world_size, world_rank;
//     MPI_Comm_size(MPI_COMM_WORLD, &world_size);
//     MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

//     int* array = NULL;
//     int sum = 0;

//     if (world_rank == 0) {
//         // Master process generates random numbers
//         array = (int*)malloc(ARRAY_SIZE * sizeof(int));
//         for (int i = 0; i < ARRAY_SIZE; ++i)
//             array[i] = rand() % 1000;
//     }

//     // Broadcast array to all processes
//     MPI_Bcast(array, ARRAY_SIZE, MPI_INT, 0, MPI_COMM_WORLD);

//     // Each process calculates sum of odd numbers in its portion of the array
//     for (int i = world_rank * (ARRAY_SIZE / world_size); i < (world_rank + 1) * (ARRAY_SIZE / world_size); ++i)
//         sum += (array[i] % 2 == 1) ? array[i] : 0;

//     // Reduce all partial sums to get the total sum
//     int total_sum;
//     MPI_Reduce(&sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

//     if (world_rank == 0)
//         printf("Total sum of odd numbers: %d\n", total_sum);

//     MPI_Finalize();
//     return 0;
// }