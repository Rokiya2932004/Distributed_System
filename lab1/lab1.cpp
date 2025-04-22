
#include <stdio.h>
#include <omp.h>
using namespace std;
#define n 1000
int main()
{
	int i; 
	double sum = 0;
	double arr[n];
	for ( i = 0; i < n; i++)
	{
		arr[i] = i * 1.0;

	}
	int num_threads;
#pragma omp parallel
	{
	num_threads = omp_get_num_threads();
	}
	printf("Number of threads: %d\n", num_threads);

	return 0;

}

