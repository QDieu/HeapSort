//
// Created by QDieu on 13.12.2017.
//
// Set the element
typedef struct{
    int key;
    void* value;
}element;

typedef int (*CompareUnitH)(int,void*,int,void*);
typedef void (*DeleteUnitH)(void*);
typedef void* (*AllocationUnitH)(void*);

typedef struct{
    element* data;
    int data_size;
    CompareUnitH Compare;
    DeleteUnitH Delete;
    AllocationUnitH Alloc;
}BHeap;

//Эл-ты сортировки
int MoreKey(int k1,void* v1,int k2,void* v2);
int LessKey(int k1,void* v1,int k2,void* v2);
//Создание кучи
BHeap * BHeap_new(CompareUnitH cmp, DeleteUnitH dlt, AllocationUnitH x);
//Удаление кучи
void BHeap_delete(BHeap* H);
//Добавление элемента
void AddElement(BHeap *H,int k, void *v);
//Изменение приоритета
void ChangeKey (BHeap *H, int i, int x);
//Сортировка вниз
void SortDownP(BHeap *H, int i);
//Сортирока вверх
void SortUpP(BHeap *H, int i);
//Добавление элементов из массива
void AddElementFromArr(BHeap *H, int* ArrayK, void** ArrayV, int n);
//Извлечение массив максимальных элементов в массивы
void MaxElementToArr (BHeap *H, int* ArrK, void** ArrV, int n);
