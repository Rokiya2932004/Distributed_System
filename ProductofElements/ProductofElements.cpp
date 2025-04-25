/*
Problem : Calculate the product of array elements using OpenMP with reduction. 

*/
#include <stdio.h>
#include <omp.h>

int main()
{
	double arr[10], product=1;
	for (int i =0; i < 10; i++)
	{
		arr[i] = (i+1);
	}

#pragma omp parallel for reduction(*: product)
	for (int i = 0; i < 10; i++)
	{
		product *= arr[i];

	}
	printf("The product of elements : %f", product);



}

