/*
Problem :Write an MPI program where process 0 sends an integer value to all other processes using 
MPI_Send, and each process receives it using MPI_Recv. 
*/

#include <stdio.h>
#include <mpi.h>

int main()
{
	int rank, size, data = 29;
	MPI_Status state;

	MPI_Init(NULL,NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
	{
		for (size_t i = 1; i < size; i++)
		{
			MPI_Send(&data, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
			printf("Process %d send data %d for process %d", rank, data, i);
		}
	}
	else {
		MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &state);
		printf("Process %d Receve data %d from process %d", rank, data, state.MPI_SOURCE);

	}
	MPI_Finalize();

}

