// Mpi.cpp : This file is a simple task to print hello using all process
//

#include <stdio.h>
#include <mpi.h>

#define MAXSize 100
int main()
{
	int rank, size;
	char message[MAXSize];

	MPI_Init(NULL,NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &rank);
	MPI_Comm_size(MPI_COMM_WORLD, &size);
	printf("Hello from process %d out of %d processes\n", rank, size);

	/* Print Process Ordered <Point to Point> */
	if (rank !=0)
	{
		sprintf_s(message , "Hello from process %d out of %d processes\n" , rank,size);
		// Sending the message to process 0
		MPI_Send(message, MAXSize, MPI_CHAR, 0, 0, MPI_COMM_WORLD);
	}
	else {
		printf("\nProcess %d: Receiving messages...\n\n", rank);
		for (size_t i = 1; i < size; i++)
		{

			MPI_Recv(message, MAXSize, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUSES_IGNORE);
			printf("%s ", message);

		}
	}




	MPI_Finalize();
}
