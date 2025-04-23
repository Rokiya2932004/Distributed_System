/*
 ####################################################
 ####################################################
                                                   ##
                                                   ##
      This code for Synchronization directives	   ##
             Critical Directive                    ##
                                                   ##
 ####################################################
 ####################################################*/

#include <stdio.h>
#include <omp.h>

int main()
{
    //  <<ATM machine>>

    int ATMbalance = 4000;
    int customerWithDrawal;
    
    printf("ATM is now open . Account Balance : %d\n\n", ATMbalance);
    printf("___________________________________________\n\n");
    omp_set_num_threads(4);
#pragma omp parallel
    {
        int customerNumber = omp_get_thread_num();
#pragma omp critical
        {

        printf("Customer %d : Approaching the ATM...\n\n ", customerNumber);
        printf("_____________________________________\n\n");
            printf("Welcome Customer %d .....\n", customerNumber);
            printf("_________________________\n\n");
            printf("Enter amount to withdraw : " );
            scanf_s("%d", &customerWithDrawal);
            if (customerWithDrawal <= ATMbalance)
            {
                ATMbalance -= customerWithDrawal;
                printf("Withdrawal successful ! , Now the ATM balance : %d \n", ATMbalance);
            }
            else if(customerWithDrawal >= ATMbalance && ATMbalance !=0) {
                printf("Insufficient balance! Current balance: %d\n", ATMbalance);
            }
            printf("Thanks for visiting , Good Bye %d :) \n\n", customerNumber);


        }

        if (ATMbalance == 0) {
            printf("Customer %d: Sorry, ATM is out of service. Balance = 0.\n\n", customerNumber+1);
        }

    }
    printf("ATM session ended, Final Balance : %d\n\n", ATMbalance);


}
