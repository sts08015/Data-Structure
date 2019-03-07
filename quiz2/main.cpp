#include <stdio.h>
#include <stdlib.h>

typedef struct bunsu
{
    int bunmo;
    int bunja;
    double val;
}Frac;

int check(int a,int b)
{
    if(b == 0) return a;
    return check(b,a%b);
}

int main()
{
    int n;
    scanf("%d",&n);
    int cur = 1;
    Frac* arr = (Frac *)calloc(0,sizeof(Frac));

    for(int i=n;i>0;i--) //bunmo
    {
        for(int j=1;j<i;j++) // bunja
        {
            int chk = check(j,i);
            if(chk == 1)
            {
                arr = (Frac *)realloc(arr,sizeof(Frac)*cur);
                Frac a = {i,j,(double)j/i};
                arr[cur-1] = a;
                cur++;
            }
        }
    }

    for(int i=0;i<cur-1;i++)
    {
        for(int j=i;j<cur-1;j++)
        {
            if(arr[i].val>arr[j].val)
            {
                Frac tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    printf("0/1\n");
    for(int i=0;i<cur-1;i++) printf("%d/%d\n",arr[i].bunja,arr[i].bunmo);
    printf("1/1");
    free(arr);
}
