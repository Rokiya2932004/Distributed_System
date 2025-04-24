/*
Problem : Create a program where process 0 sends a number to process 1, then process 1 adds 10 and 
sends it back. 
*/

#include <stdio.h>
#include <mpi.h>

int main()
{
	int rank, size, data = 20;
	MPI_Status state;

	MPI_Init(NULL , NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0)
	{
		MPI_Send(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
		printf("Process %d send data %d for process 1\n", rank, data);
		MPI_Recv(&data, 1, MPI_INT,1,1, MPI_COMM_WORLD, &state);
		printf("\nProcess %d Recive the final addition result %d from process %d\n ", rank, data, state.MPI_SOURCE);


	}
	else if (rank == 1) {
		MPI_Recv(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &state);
		printf("\nProcess %d Recive data %d from process %d and added 10\n ", rank, data, state.MPI_SOURCE);
		data += 10;

		MPI_Send(&data, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
		printf("\nProcess %d Send the result %d back to process %d\n", rank, data, state.MPI_SOURCE);


	}

	MPI_Finalize();
}
