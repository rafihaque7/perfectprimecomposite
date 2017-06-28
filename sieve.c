#include "sieve.h"
# include <stdio.h>
#include <math.h>
#include "bv.c"

//Stores 1 if it is prime in the bitvector
//Code given by the professor
void sieve(bitV *v)
{
    oneVec(v);
        clrBit(v,0);
       clrBit(v,1);
       setBit(v,2);

    for(uint32_t i =2; i<=sqrtl(lenVec(v)); i+=1)
    {
        if(valBit(v,i))
        {
            for(uint32_t k=0; (k+1)*i<=lenVec(v); k+=1)
            {
            clrBit(v,(k+i)*i);
            }
        }
    }
    return;
}
