#include <stdio.h>

typedef struct _move
{
    int a;
    int b;
} Move;

Move arr[12345678];
void hanoi(long long num,int from,int by,int to,long long* cnt,bool chk)
{
    if(num == 1)
    {
        if(chk)
            arr[*cnt] = {from,to};//printf("%d %d\n",from,to);
        (*cnt) ++;
        return;
    }
    hanoi(num-1,from,to,by,cnt,chk);
    if(chk)
        arr[*cnt] = {from,to};//printf("%d %d\n",from,to);
    (*cnt) ++;
    hanoi(num-1,by,from,to,cnt,chk);
}

int main()
{
    long long n,cnt=0;
    scanf("%lld",&n);
    bool chk = true;
    if(n>20)
        chk = false;
    hanoi(n,1,2,3,&cnt,chk);
    printf("%d\n",cnt);
    if(chk)
    {
        for(int i=0; i<cnt; i++)
            printf("%d %d\n",arr[i].a,arr[i].b);
    }
}
