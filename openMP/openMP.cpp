
#include<stdio.h>
#include<omp.h>

#define size 100

int main()
{
	double sum=0.0;
	double arr[size];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = i * 1.0;
	}
	int numThreads;
#pragma omp parallel
	{
		numThreads = omp_get_num_threads();
	
	}
	printf("Num of threads  : %d\n", numThreads);
	//int nThread = omp_get_num_threads();
	//printf("\nNum of threads  : %d\n", nThread);
	//omp_set_num_threads(4);
	int maxi = omp_get_max_threads();
	printf("max_threads : %d\n", maxi);

	double Starttime = omp_get_wtime();

#pragma omp parallel reduction(+: sum)
	{
		for (size_t i = 0; i < size; i++)
		{
			sum += arr[i];
		}
	
	}
		printf("Sum : %f\n", sum);

		double Endtime = omp_get_wtime();

		//Section 
#pragma omp parallel sections
		{
#pragma omp section
			{

				printf("From Section 1 : Starting Time : %f\n", Starttime);

			}
#pragma omp section
			{
				printf("From Section 2 : Ending Time : %f\n", Endtime);


			}
		}

		//critical 
		int count = 0;
#pragma omp parallel for
		for (int i = 0; i < 10; i++)
		{
#pragma omp critical
			{
				count++;
				printf("Thread %d incremented counter to: %d\n", omp_get_thread_num(), count);
			}
		}
		
		//Automic
		int AutoCount = 0;
#pragma omp parallel for
		for (int i = 0; i < 10; i++)
		{
#pragma omp atomic
			AutoCount++;
		}
		printf("AutoCount = %d\n", AutoCount);


}



//#pragma omp parallel for
//for (int i = 0; i < 10; i++)
//{
//#pragma omp atomic
//	AutoCount++;
//}
//
//printf("AutoCount = %d\n", AutoCount);
//




