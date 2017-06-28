#include <stdio.h>
#include "sieve.c"
#include <math.h>
#include <stdlib.h>


void regularFactorization(int n);
int ifPerfect(int n);
void sprimeFactorization(int n, int *primes);

int main(void)
{
    int n = 100000; //Up to how many numbers
    bitV * newVec1 = newVec(n);
    sieve(newVec1);

//To store all the prime numbers
int *primes;
primes = malloc(n*sizeof(int));



    int j=0; //J is used for storing prime numbers primes[0]=2
    //To print the prime numbers
    for(uint32_t i=2;i<=lenVec(newVec1);i++)
    {
        printf("%d ",i);

        if(valBit(newVec1,i)==1) //Put p next to all the prime numbers
        {
            printf("P\n");
            primes[j] =i; //store the number itself
            j++;
        }
        else if(valBit(newVec1,i)==0 && ifPerfect(i)==1) //When it is not perfect but is a perfect number
        {
            printf("C: " );
            sprimeFactorization(i,primes);
            printf("%d ",i);
            printf("E: ");
            regularFactorization(i);
            printf("\n");
        }
        else
        {
            printf("C: " );
            sprimeFactorization(i,primes);
        }
    }
//regularFactorization(6);
//sprimeFactorization(6,primes);
//printf("%d",ifPerfect(3));
delVec(newVec1);
return 0;
}



//To factor perfect numbers
void regularFactorization(int n) //Very simple,
{
for(int i=1; i<n;i++) //The factorization is up to the number
{
    if(n%i==0)
    {
        printf("%d ", i);
    }
}
}

//Returns 1 if it is a perfect number
int ifPerfect(int n)
{
    int total = 0;
    for(int i=1; i<n;i++)
    {
        if(n%i==0)
        {
            total+=i;
        }
    }
    return total==n;

}

//Gives prime factorization of n
void sprimeFactorization(int n, int *primes)
{

    int j=0;
    while(n>1) //The loop only occurs when it is greater than the number
    {
        if(n%primes[j]==0)
        {
            n/=primes[j];
            printf("%d ",primes[j]);
        }
        else{
            j++;
        }

    }
    printf("\n");

}
