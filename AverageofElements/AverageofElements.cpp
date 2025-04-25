/*

Problem : Calculate the average of array elements using OpenMP. Ensure synchronization when 
adding values. 

*/

#include <stdio.h>
#include <omp.h>

int main()
{
	int arr[10]={0}, sum = 0, numThreads;
	double avg = 0.0;
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i + 1;
	}

#pragma omp parallel
	{
		numThreads = omp_get_num_threads();
	}
		printf("%d", numThreads);
#pragma omp parallel for schedule(static)

		for (int i = 0; i < 10; i++)
		{
#pragma omp critical
			{
			sum += arr[i];
			}
			printf("\nThread %d added %d \n", omp_get_thread_num(), arr[i]);
		}

		printf("\nsum : %d\n", sum);
#pragma omp barrier
		avg =(double) sum / 10;

	printf("\nThe Avarage = %.2f \n", avg);
}

