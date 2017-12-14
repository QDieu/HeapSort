#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXN 100

BHeap * BHeap_new(CompareUnitH cmp, DeleteUnitH dlt, AllocationUnitH x){
    BHeap* Heap;
    Heap = calloc (1,sizeof(BHeap));
    Heap->data=calloc(MAXN,sizeof(element));
    Heap->Compare=cmp;
    Heap->Delete=dlt;
    Heap->Alloc=x;
    return Heap;
}

void BHeap_delete(BHeap* H){
    for (int i=0;i<H->data_size;i++){
        H->Delete(H->data[i].value);
    }
    free(H->data);
    free(H);
}

int MoreKey(int k1,void* v1, int k2, void* v2){
    if (k1>k2) return 1;
    if (k1==k2) return 0;
    if (k1<k2) return -1;
}

int LessKey(int k1,void* v1, int k2, void* v2){
    if (k1<k2) return 1;
    if (k1==k2) return 0;
    if (k1>k2) return -1;
}

void SortDownP(BHeap * H, int i){
    element temp;
    int left = 2*i+1;
    int right = 2*i+2;
    int largest = i;
    if (left<H->data_size)
        if(H->Compare(H->data[i].key,H->data[i].value,H->data[left].key,H->data[left].value)!=1)
            largest=left;
    if (right<H->data_size)
        if(H->Compare(H->data[largest].key,H->data[largest].value,H->data[right].key,H->data[right].value)!=1)
            largest=right;
    if (largest!=i){
        temp=H->data[i];
        H->data[i]=H->data[largest];
        H->data[largest]=temp;
        SortDownP(H,largest);
    }
    /*else
    {
        SortDownP(H, left);
        SortDownP(H,right);
    }
    */
}

void SortUpP(BHeap *H, int i){
    element temp;
    int parent = (i-1)/2;
    while (parent>=0 && i>0)
    {
        if(H->Compare(H->data[parent].key,H->data[parent].value,H->data[i].key,H->data[i].value)!=1)
        {
            temp=H->data[parent];
            H->data[parent]=H->data[i];
            H->data[i]=temp;
        }
        i=parent;
        parent=(i-1)/2;
    }
}

void AddElement(BHeap *H,int k, void* v)
{
    element temp;
    int i = H->data_size;
    H->data[i].value=H->Alloc(v);
    H->data[i].key=k;
    if(i!=0) SortUpP(H,i);
    H->data_size ++;
}

void AddElementFromArr(BHeap *H, int* ArrayK, void** ArrayV, int n)
{
    int i;
    for (i=0;i<n;i++) AddElement(H,ArrayK[i],ArrayV[i]);
}

void ChangeKey(BHeap *H, int i, int x){
    H->data[i].key=x;
    SortUpP(H,i);
}

element GetNullElement (BHeap *H)
{
    element x;
    x.value=H->Alloc(H->data[0].value);
    H->Delete(H->data[0].value);
    x.key=H->data[0].key;
    H->data[0]=H->data[H->data_size-1];
    H->data_size--;
    SortDownP(H,0);
    return x;
}

void MaxElementToArr (BHeap *H, int* ArrK, void** ArrV, int n)
{
    for(int i=0;i<n;i++)
    {
        element tmp = GetNullElement(H);
        ArrK[i]=tmp.key;
        ArrV[i]=tmp.value;
    }
}