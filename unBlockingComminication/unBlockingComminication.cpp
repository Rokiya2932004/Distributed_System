
#include <stdio.h>
#include <mpi.h>

int main()
{
	int rank, size, data = 100;
	MPI_Init(NULL,NULL);
	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);

	MPI_Request req;
	MPI_Status state;
	if (rank == 1)
	{
		printf("Process %d send data and continuing work...\n",rank);

		MPI_Isend(&data, 1, MPI_INT, 2, 0, MPI_COMM_WORLD, &req);
		printf("Process %d: Doing something else...\n",rank);

		MPI_Wait(&req, &state);
		printf("Process %d: Send completed!\n",rank);
	}
	else if (rank == 2) {

		MPI_Irecv(&data, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, &req);
		MPI_Wait(&req, &state);
		printf("Process %d: Received data = %d\n",rank, data);
	}

	MPI_Finalize();

}
