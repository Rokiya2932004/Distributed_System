/*
 Problem : Use OpenMP to parallelize finding the maximum value in an array. Apply synchronization to 
ensure safe updates. 

###--NOTE --> their is more than one solution  

*/

#include <stdio.h>
#include <omp.h>

int main()
{
	int arr[10];
	for (size_t i = 0; i < 10; i++)
	{
		arr[i] = i + 5;
	}

	int max = arr[0];
#pragma omp parallel for schedule(static)
	for (size_t i = 0; i < 10; i++)
	{
#pragma omp critical
		{
			if (arr[i]>max)
			{
				max = arr[i];

			}
		}
	}
	printf("The max %d", max);


}

