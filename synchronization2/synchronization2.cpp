/*
 ####################################################
 ####################################################
                                                   ##
                                                   ##
      This code for Synchronization directives	   ##
             Atomic & Barrier directive            ##
                                                   ##
 ####################################################
 ####################################################*/
#include <stdio.h>
#include <omp.h>

int main()
{
    int AtomicCount = 0;
    omp_set_num_threads(4);
    printf("\nAtomic Direcive :)\n");

#pragma omp parallel
    {

        for (size_t i = 0; i < 5; i++)
        {
#pragma omp critical
            {
                printf("iteration %d ->Thread %d increment counter \n", i, omp_get_thread_num());
            }
#pragma omp atomic
            AtomicCount++; // each 4 threads will increament AtomicCount 5 so the final result : 4*5 =20

        }
    }
        printf("Final count: %d\n", AtomicCount);

        printf("___________________________________________________________________________\n\n");
        printf("\nBarrier  Direcive :)\n");
        printf("_____________________\n\n");

#pragma omp parallel
    {

        int hiker = omp_get_thread_num();

        printf("\nHiker %d Reached to checkpoint 1 \n", hiker);

#pragma omp barrier
        printf("\nHiker %d Continuing to next stage \n", hiker);

    
    }

}
