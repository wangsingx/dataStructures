#include <stdlib.h>
#include <time.h>

int *randNum(int count, int maxNum)
{
    int i, *num;
    srand((int)time(0));
    num = (int *)calloc(sizeof(int), count);
    for(i=0;i<count;i++)
    {
        num[i] = rand()%(maxNum + 1);
    }
    return num;
}




