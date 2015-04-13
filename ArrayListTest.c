#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "arrayList.h"

arrayList *init_array(int *num, int count)
{
    int i;
    arrayList *testArray = arrayListCreat(1000);
    for(i=0;i<count;i++)
    {
        if(!arrayListAdd(testArray, num[i]))
        {
            printf("error occur\t count:%d;value:%d\n",i,num[i]);
            break;
        }
    }
    return testArray;
}

void arrayListRemoveTest(arrayList *array)
{
    int i,off;
    for(i=0;i<5;i++)
    {
        off = rand()%201;
        printf("off:%d\n",off);
        arrayListRemove(array, off);
        arrayListPrint(array);
    }
}

void arrayListSearchTest(arrayList *array)
{
    int i, ret, value;
    for(i=0;i<100;i++)
    {
        value = rand()%501;
        ret = arrayListSearch(array,value);
        if(ret >= 0)
            printf("---------value:%d;    offset:%d\n",value, ret);
    }
}

void arrayListSetTest(arrayList *array)
{
    int i, offset, value;
    for(i=0;i<10;i++)
    {
        offset = rand()%201;
        value = rand()%501 + 1000;
        arrayListSet(array,offset,value);
        printf("---------offset:%d;    value:%d\n",offset, value);
    }
    arrayListPrint(array);
}

void arrayListGetTest(arrayList *array)
{
    int i, ret, offset, value=-1;
    for(i=0;i<10;i++)
    {
        offset = rand()%201;
        ret = arrayListGet(array,offset,&value);
        printf("---ret:%d------offset:%d;    value:%d\n",ret, offset, value);
    }
}

int array_main(int argc, char ** argv)
{
    int *num = randNum(100,500);
    //create test
    arrayList *testArray = init_array(num, 100);
    arrayListPrint(testArray);

//    arrayListRemoveTest(testArray);
//    arrayListSearchTest(testArray);
//    arrayListSetTest(testArray);
//    arrayListGetTest(testArray);



    arrayListDelete(testArray);
    testArray = NULL;
    free(num);
    return 0;
}
