/*
Use OpenMP work-sharing to compute the average of mathematical operations.
Synchronization is required to maintain safe updates.

NOTE : U can solve it using two arrays it's not the only solution 
*/

#include <stdio.h>
#include <omp.h>

int main()
{
	double num1, num2;
	double OperationSUM = 0, avg=0;

	printf("Enter two numbers:\n");
	printf("Num1: ");
	scanf_s("%lf", &num1);

	printf("Num2: ");
	scanf_s("%lf", &num2);


	double MathOPs[4] = { (num1 + num2),(num1 - num2),(num1 / num2),(num1 * num2) };

#pragma omp parallel for schedule(static)
	for (int i = 0; i < 4; i++)
	{
#pragma omp critical
		{
			OperationSUM += MathOPs[i];

		}
	}
	avg = OperationSUM / 4;
	printf("Average of Mathematical Operations is %.2lf \n", avg);


}
