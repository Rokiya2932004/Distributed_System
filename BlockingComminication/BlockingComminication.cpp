

#include <stdio.h>
#include <mpi.h>

int main()
{
	int processID, totalNumProcess,message = 29;
	MPI_Status state;

	MPI_Init(NULL , NULL);

	MPI_Comm_rank(MPI_COMM_WORLD, &processID);
	MPI_Comm_size(MPI_COMM_WORLD, &totalNumProcess);


	if (processID == 0)
	{
		printf("Good Morning :) your holiday at %d\n", message);
		for (size_t i = 1; i < totalNumProcess; i++)
		{
			MPI_Send(&message, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		}
	}

	// Without Ordering The Proceess
	else{

		MPI_Recv(&message, 1, MPI_INT, MPI_ANY_SOURCE, 0, MPI_COMM_WORLD, &state);
		printf("Good Morning :) I am process %d , Thank You Process %d!\n", processID, state.MPI_SOURCE);

	}


	MPI_Finalize();

}

