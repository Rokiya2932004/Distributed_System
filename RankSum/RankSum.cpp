/*
Problem : Each process sends its rank to process 0 using point-to-point communication. Process 0 
sums all ranks and prints the total. 

*/

#include <stdio.h>
#include <mpi.h>

int main()
{
	int rank, size, sum = 0;
	MPI_Status state;

	MPI_Init(NULL , NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	int data = rank;

	if (rank !=0)
	{
		MPI_Send(&data, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
		printf("Process %d Send it's rank %d to process 0\n", rank, data);
	}
	else if(rank == 0 ) {
		for (int ProcessID = 1; ProcessID < size; ProcessID++)
		{
			MPI_Recv(&data, 1, MPI_INT, ProcessID, 0, MPI_COMM_WORLD,&state);
			printf("Process %d Recive the rank %d from process %d\n", rank, data, state.MPI_SOURCE);
			sum += data;

		}
		printf("The Total Rank : %d", sum);

	}

	MPI_Finalize();
}

