#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[51];
    fgets(arr,51,stdin);
    for(int i=0;i<strlen(arr)-1;i++) printf("%c",arr[i]);
    printf(":%d",strlen(arr)-1);
}
