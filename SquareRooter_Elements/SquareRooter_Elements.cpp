/*
problem : Use OpenMP work-sharing directives to compute the square root of all elements. No
synchronization needed.

*/
#include <stdio.h>
#include <math.h>
#include <omp.h>

int main()
{
	double squareElements[5], arr[5], sqrEachelemnt = 0;
	arr[0] = 25;
	for (int i = 1; i < 5; i++)
	{
		arr[i] = arr[i - 1] * 2;
	}
#pragma omp parallel for reduction(+: sqrEachelemnt)
	for (int i = 0; i < 5; i++)
	{
		sqrEachelemnt = sqrt(arr[i]);
		squareElements[i] = sqrt(arr[i]);
	}

	printf("The square root of all elemnts %.2f\n", sqrEachelemnt);
	printf("_____________________________________________\n");
	for (int i = 0; i < 5; i++)
	{
		printf("The Square root of index %d which it's elemnt = %.2f is %.2f \n", (i + 1), arr[i], squareElements[i]);

	}

}

