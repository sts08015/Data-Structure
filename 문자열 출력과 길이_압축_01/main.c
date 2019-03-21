#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[101];
    char brr[101];
    int cnt = 0;
    fgets(arr,101,stdin);
    int len = strlen(arr);
    char tmp = ' ';

    for(int i=0; i<len-1; i++)
    {
        if(tmp == ' ' && arr[i] == ' ')
        {
            continue;
        }
        else if(tmp == ' ' && arr[i]!=' ') brr[cnt++] = arr[i];
        else if(tmp != ' ' && arr[i] == ' ') brr[cnt++] = arr[i];
        else if(tmp != ' ' && arr[i]!= ' ') brr[cnt++] = arr[i];
        tmp = arr[i];
    }
    if(brr[cnt-1] == ' ') cnt--;
    for(int i=0; i<cnt; i++)
        printf("%c",brr[i]);
    printf(":%d",cnt);
}
