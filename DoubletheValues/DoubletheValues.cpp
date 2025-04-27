/*
Use OpenMP to double each element in an array. No synchronization needed.
*/
#include <stdio.h>

int main()
{
	double arr[5] = { 10,20,30,40,50 };
	double Doubledarr[5];
#pragma omp parallel for schedule(static)
	for (int i = 0; i < 5; i++)
	{
		Doubledarr[i] = arr[i] * 2;
		printf("The value %f from Array1 Doubled to %f in Array2\n", arr[i], Doubledarr[i]);
	}

}

