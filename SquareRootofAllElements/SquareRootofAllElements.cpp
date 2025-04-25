/*
problem : Use OpenMP work-sharing directives to compute the square root of all elements. No 
synchronization needed. 

*/
#include <stdio.h>
#include <omp.h>

int main()
{
	int squareElements[5], arr[5] , sqrEachelemnt = 0;

	for (int i = 0; i < 5; i++) // 5	10	15	20	25
	{
		arr[i] = i + 5;
	}
#pragma omp parallel for reduction(+: sqrEachelemnt)
	for (int i = 0; i < 5; i++)
	{
		sqrEachelemnt = arr[i] * arr[i];
		squareElements[i] = arr[i] * arr[i];
	}

	printf("The square root of all elemnts %d\n", sqrEachelemnt);
	printf("_____________________________________________\n");
	for (int i = 0; i < 5; i++)
	{
		printf("The Square root of index %d which it's elemnt = %d is %d \n", (i+1),arr[i], squareElements[i]);

	}

}

