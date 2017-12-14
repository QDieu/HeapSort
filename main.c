#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "heap2.h"

void* AllocIntH(void* x)
{
    int* i=malloc(sizeof(int));
    *i=*(int*)x;
    return i;
}

void DeleteIntH (void* x)
{
    free (x);
}

int main() {

    const N = 10;

    int i;
    int* ArrK= malloc(sizeof(int)*N);
    void** ArrV=malloc(sizeof(int*)*N);
    for (i = 0; i< N;i++)
    {
        ArrK[i]=N-1-i;
        ArrV[i]=malloc(sizeof(int));
        *(int*)(ArrV[i])=(ArrK[i])*5;
    }

    for (i=0;i<N; i++) printf("%d %d\n", ArrK[i], *(int*)ArrV[i]);
    BHeap * Ases = BHeap_new (MoreKey,DeleteIntH,AllocIntH);
    AddElementFromArr(Ases,ArrK, ArrV, N);
    SortDownP(Ases,0);
    ChangeKey(Ases,3, 10);
    MaxElementToArr(Ases,ArrK,ArrV,N);
    BHeap_delete (Ases);
    printf("\n");
    for (i=0;i<N;i++) printf ("%d %d\n",ArrK[i],*(int*)ArrV[i]);
    for (i=0;i<N;i++)
    {
        free(ArrV[i]);
    }
    free(ArrV);
    free(ArrK);
    return 0;
}