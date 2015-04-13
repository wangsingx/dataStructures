#ifndef _ARRAY_LIST_H
#define _ARRAY_LIST_H

#define MAX_SIZE_LIMIT  1024

typedef struct {
    int count;
    int maxSize;
    int *head;
}arrayList;

arrayList *arrayListCreat(int maxSize);
void arrayListDelete(arrayList * array);
arrayList *arrayListAdd(arrayList *array, int value);
arrayList *arrayListRemove(arrayList *array, int location);
int arrayListSearch(arrayList *array, int value);
arrayList *arrayListSet(arrayList *array, int location, int value);
int arrayListGet(arrayList *array, int location, int *value);
void arrayListPrint(arrayList *array);

#endif // _ARRAY_LIST_H
