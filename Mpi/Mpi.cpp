// Mpi.cpp : This file is a simple task to print hello using all process
//

#include <stdio.h>
#include <mpi.h>

int main()
{
	MPI_Init(NULL,NULL);
	int rank, size;
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("Hello from process %d out of %d processes\n", rank, size);


	MPI_Finalize();
}
