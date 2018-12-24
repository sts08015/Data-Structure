#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num = 0;
    int cnt = 0;
    int* arr = (int*)calloc(sizeof(int),5);
    while(1)
    {
        printf("input number %d: ",cnt);
        scanf("%d",&num);
        if(num == -1) break;
        if(cnt>=sizeof(arr)/sizeof(int))
        {
            arr = (int*)realloc(arr,sizeof(int)*(cnt+2));
        }
        arr[cnt] = num;
        cnt++;
    }
    for(int i =0;i<cnt;i++) printf("%d ",arr[i]);
    printf("\n%d",cnt);
    printf("\n%d",sizeof(arr)/sizeof(int));
    free(arr);
    return 0;
}
