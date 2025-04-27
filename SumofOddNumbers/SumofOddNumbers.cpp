/*
Problem : Use OpenMP to compute the sum of odd numbers in an array. Synchronize the sum 
operation. 
*/

#include <stdio.h>
#include <omp.h>

int main()
{
	int arr[10] = { 7,3,8,5,2,9,1,3,4,8 };
	int sum = 0;
#pragma omp parallel for schedule(static)
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] %2 !=0)
		{
#pragma omp critical
		{
				sum += arr[i];

		}
		}
	}
	printf("The Sum of Odd Numbers : %d", sum);

}

