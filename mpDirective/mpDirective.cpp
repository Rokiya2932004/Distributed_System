
/*
####################################################
####################################################
												   ##
												   ##
		This code for Work-Sharing Drectives	   ##
												   ##
												   ##
												   ##
												   ##
####################################################
####################################################
*/

#include <stdio.h>
#include <omp.h>


int main()
{
	int arr[10];
	int arr2[10];
	int sum[10];
	int Iterations[10] = {0};

	double startTime[10] = {0};
	double EndTime[10] = {0};
	double Duration[10] = {0};

	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 10;
		arr2[i] = i + 20;
	}
	int nThreads;
#pragma omp parallel
	{
		 nThreads = omp_get_num_threads();
	}
		printf("Num of Threads : %d ", nThreads);

	/************ For ****************/

	omp_set_num_threads(5);
	printf("\nStatic Schedule :)\n");
	printf("__________________\n\n");
#pragma omp parallel for schedule(static)
		for (int i = 0; i < 10; i++)
		{
			sum[i] = arr[i] + arr2[i];
			printf("Thread %d: sum[%d] = %d\n", omp_get_thread_num(), i, sum[i]);
		}
		printf("\nNote : we just use 5 threads so each one take 2 from the iteration\n");


		printf("___________________________________________________________________________\n\n");


		printf("\nDynamic Schedule :)\n");
		printf("_____________________\n\n");
		omp_set_num_threads(8);

#pragma omp parallel for schedule(dynamic)
		for (int i = 0; i < 10; i++)
		{
			int currentThread = omp_get_thread_num();
			sum[i] = arr[i] + arr2[i];
#pragma omp atomic
			Iterations[currentThread]++;
			printf("Thread %d: sum[%d] = %d\n", omp_get_thread_num(), i, sum[i]);
		}
		int maxThread = 0;
		int maxIterations = Iterations[0];
		for (size_t i = 0; i < 10; i++)
		{
			if (Iterations[i] > maxIterations) {
				maxIterations = Iterations[i];
				maxThread = i;
		}

		}
		printf("\nThe max thread work in dynamic schedule from all 8 threads is : %d\n", maxThread);


		printf("___________________________________________________________________________\n\n");


		printf("\nGuided Schedule :)\n");
		printf("_____________________\n\n");
		omp_set_num_threads(8);
#pragma omp parallel
		{
			double StartThreadTime = omp_get_wtime();
			int threadNum = omp_get_thread_num();

#pragma omp parallel for schedule(guided)
		for (int i = 0; i < 10; i++)
		{
			sum[i] = arr[i] + arr2[i];

			printf("Thread %d: sum[%d] = %d --> this thread start it's execution time at : %f\n", omp_get_thread_num(), i, sum[i], StartThreadTime);
		}
		double EndThreadTime = omp_get_wtime();

		startTime[threadNum] = StartThreadTime;
		EndTime[threadNum] = EndThreadTime;
		Duration[threadNum] = EndThreadTime - StartThreadTime;

		}
		int maxThreadTime = 0;
		int minThreadTime = 0;
		double minTime = Duration[0];
		double maxTime = Duration[0];
		for (size_t i = 0; i < 10; i++)
		{
			if (Duration[i] > 0 && Duration[i] < minTime) {
				minTime = Duration[i];
				minThreadTime = i;
		}	
			else if (Duration[i] > 0 && Duration[i] > maxTime) {
				maxTime = Duration[i];
				maxThreadTime = i;
		}

		}
		printf("\nThe Thread that takes min exicution time is : %d with time : %f  seconds\n", minThreadTime, minTime);
		printf("\nThe Thread that takes max exicution time is : %d with time : %f  seconds\n", maxThreadTime, maxTime);
		printf("\nNote : the Guided code has a problem cause of Nested Parallelism lead to print the working thread just 0 and the max / min is different :( <<if U fix it tell me ^^ >> \n");

		printf("\n\n___________________________________________________________________________\n\n");


	/************ Section  ****************/

		printf("\nSection Directive :)\n");
		printf("_____________________\n\n");
			printf("The max threads used here is : 4\n"); 
			omp_set_num_threads(4);
#pragma omp parallel
		{
#pragma omp sections
			{
#pragma omp section
				{
					printf("\nThis is section 1 used to add two numbers\n");
					int x=10, y=20;
					printf("\n%d + %d = %d", x, y, (x + y));
				}			
#pragma omp section		
				{			
					printf("\n\nThis is section 2 used to sub two numbers\n");
					int x=10, y=20;
					printf("\n%d - %d = %d", x, y, (x - y));
				}			
#pragma omp section			
				{			
					printf("\n\nThis is section 3 used to divide two numbers\n");
					int x=100, y=20;
					printf("\n%d / %d = %d", x, y, (x / y));
				}			
#pragma omp section			
				{			
					printf("\n\nThis is section 4 used to multiply two numbers\n");
					int x=10, y=20;
					printf("\n%d * %d = %d", x, y, (x * y));
				}
			}
		}
		printf("\n\n___________________________________________________________________________\n\n");


		/************ Single  ****************/

		printf("\nSingle Directive :)\n");
		printf("_____________________\n\n");
		
		omp_set_num_threads(8);
#pragma omp parallel
		{
		int threadNum = omp_get_thread_num();
		printf("\nThread %d: Starting work\n", threadNum);

#pragma omp single
			{
				printf("\nThread %d i am single thread without wait\n ", threadNum);
			}
#pragma omp single nowait
			{
				printf("\nThread %d i am single thread with wait \n", threadNum);
			}
			printf("\nThread %d: Continuing work\n", threadNum);

		}

}

