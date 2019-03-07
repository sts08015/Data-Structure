#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* arr = (int*)calloc(1,sizeof(int));
    arr[0] = 1;
    arr = (int*)realloc(arr,sizeof(int)*2);
    for(int i=0;i<=1;i++) printf("%d ",arr[i]);
}
