#include "bv.h"
#include <stdint.h>
#include <stdlib.h>



bitV * newVec(uint32_t l)
{
    bitV * v = malloc(sizeof(struct bitV));
    v->l = l;
    v->v = calloc(v->l, sizeof(int));

    return v;

}

void delVec(bitV * a)
{
    free(a->v);
    free(a);

}
//
void oneVec(bitV * a)
{
    //a->v = calloc(a->l, sizeof(int));

    for(uint32_t i =0; i<a->l;i++){
        //a->v[i] = 1;
        setBit(a,i);
    }

}
//
void setBit(bitV *A,uint32_t k)
{

A->v[k >> 3] |= (01 << (k & 07));
//a->v[k] = 1;
}
void clrBit(bitV *A,uint32_t k)
{
A->v[k >> 3] &= ~(01 << (k & 07));
//a->v[k >> 3] &= ~(01 << (k & 07));
//a->v[k] =0;
}
//
uint8_t valBit(bitV *A, uint32_t k)
{
    //return a->v[t];
    return (A->v[k >> 3] & (01 << (k & 07))) >> (k & 07);
}
//
uint32_t lenVec(bitV *a)
{
    return a->l;
}
