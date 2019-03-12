#include <stdio.h>

void Swap(int ** a,int ** b)
{
    int *tmp;
    tmp = *b;
    *b = *a;
    *a = tmp;
}
int main()
{
    int a = 1;
    int b = 2;
    int * a1 = &a;
    int * b1 = &b;
    Swap(&a1,&b1);
    printf("%d %d",*a1,*b1);
}
