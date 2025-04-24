/*
Problem : Process 0 starts with value 1. Each process adds its rank to this value and passes it around. 
*/
#include <stdio.h>
#include <mpi.h>

int main()
{
	int rank, size, data = 1;
	MPI_Status state;

	MPI_Init(NULL, NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	if (rank == 0 )
	{
		MPI_Send(&data, 1, MPI_INT, rank + 1, 0, MPI_COMM_WORLD);
		printf("\nprocess %d sent %d to process %d\n", rank, data, (rank + 1));

		MPI_Recv(&data, 1, MPI_INT, size - 1, 0, MPI_COMM_WORLD, &state);
		printf("\nprocess %d Resive %d from process %d\n", rank, data, (size - 1));

		data += rank;

		printf("\n____________________________________\n");
		printf("| Final result at process 0: %d :) |\n", data);
		printf("|__________________________________|");
	}
	else {
		MPI_Recv(&data, 1, MPI_INT, rank - 1, 0, MPI_COMM_WORLD, &state);
		printf("\nprocess %d Resive %d from process %d\n", rank, data, (rank + 1));

		data += rank;
		int nextRank = (rank + 1) % size;
		MPI_Send(&data, 1, MPI_INT, nextRank, 0, MPI_COMM_WORLD);
		printf("\nprocess %d sent %d to process %d\n", rank, data, (rank + 1));


	}
	MPI_Finalize();


}

