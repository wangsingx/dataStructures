#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayList.h"

/*
 *create an arraylist
 */
arrayList *arrayListCreat(int maxSize)
{
    if(maxSize <= 0)
    {
        printf("invalid argument\n");
        return NULL;
    }

    arrayList *array = (arrayList *)malloc(sizeof(arrayList));
    if(!array)
    {
        printf("error occur when alloc space for array\n");
        return NULL;
    }

    array->count = 0;
    array->maxSize = maxSize<MAX_SIZE_LIMIT?maxSize:MAX_SIZE_LIMIT;
    array->head = (int *)malloc(sizeof(int) * array->maxSize);
    if(!array->head)
    {
        printf("error occur when alloc data space for array\n");
        return NULL;
    }
    printf("create an arrayList successfully\n");
    return array;
}

/*
 *delete the arraylist
 */
void arrayListDelete(arrayList *array)
{
    if(!array)
    {
        printf("nothing to do \b");
        return;
    }

    if(!array->head)
        printf("no data space to free\n");
    else
        free(array->head);
    array->head = NULL;
    free(array);
    printf("delet arrayList successfully\n");
}

/*
 *add an integer element to array tail
 */
arrayList *arrayListAdd(arrayList *array, int value)
{
    if(!array)
    {
        printf("nothing to do");
        return array;
    }
    if(!array->head)
    {
        printf("no data space\n");
    }

    if(array->count >= array->maxSize)
    {
        printf("add failed!! the array count has reach the maxmium\n");
        return array;
    }

    array->head[array->count] = value;
    array->count++;
    return array;
}

/*
 *remove an integer from the array
 *arg:location,the offset of the array
 */
arrayList *arrayListRemove(arrayList *array, int location)
{
    if(!array)
    {
        printf("nothing to do \n");
        return array;
    }
    if(!array->head)
    {
        printf("no data space\n");
    }

    if(location >= array->count || location < 0)
    {
        printf("the location is an invalid argument \n");
        return array;
    }

    array->head[location] = 0;
    printf("%d\n",array->count-location);
    memmove(array->head + location, array->head + (location + 1), (array->count - location)*sizeof(int));
    array->count--;
    return array;
}

/*
 *search a value from the array
 *return the offset in the array,return -1 when not find
 */
int arrayListSearch(arrayList *array, int value)
{
    int i;
    if(!array)
    {
        printf("nothing to do \n");
        return -1;
    }
    if(!array->head)
    {
        printf("no data space\n");
        return -1;
    }

    for(i=0;i<=array->count;i++)
    {
        if(value == array->head[i])
            return i;
    }
    printf("the value %d can't be found int array\n", value);
    return -2;
}

/*
 *set the value in the specified offset
 */
arrayList *arrayListSet(arrayList *array, int location, int value)
{
    if(!array)
    {
        printf("nothing to do\n");
        return array;
    }
    if(!array->head)
    {
        printf("no data space\n");
    }

    if(location >= array->count || location < 0)
    {
        printf("the location is an invalid argument \n");
        return array;
    }
    array->head[location] = value;
    return array;
}

/*
 *get the value in the specified offset
 *return 0 success,-1 failed
 */
int arrayListGet(arrayList *array, int location, int *value)
{
    if(!array)
    {
        printf("nothing to do\n");
        return -1;
    }
    if(!array->head)
    {
        printf("no data space\n");
    }

    if(location >= array->count || location < 0)
    {
        printf("the location is an invalid argument \n");
        return -1;
    }

    *value = array->head[location];
    return 0;
}

/*
 *print the value in the array
 */
void arrayListPrint(arrayList *array)
{
    if(!array)
    {
        printf("nothing to do\n");
        return;
    }
    if(!array->head)
    {
        printf("no data space\n");
        return;
    }

    int i;
    printf("arraylist has %d integer\n",array->count);
    for(i=0;i<array->count;i++)
    {
        printf("%4d ",array->head[i]);
        if(i%10 == 9)
        {
            printf("\n");
        }
    }
    printf("\n-----------------------------------------------------------------\n");
}
