#include <stdio.h>
// solve hanoi using pointer
/*
void Hanoi(int num,char from,char by,char to)
{
    if(num == 1)
    {
        printf("1 %c %c\n",from,to);
        return;
    }
    Hanoi(num-1,from,to,by);
    printf("%d %c %c\n",num,from,to);
    Hanoi(num-1,by,from,to);
}
int main()
{
    int n;
    scanf("%d",&n);
    Hanoi(n,'A','B','C');
    return 0;
}*/

void hanoi(int n,char * from, char * by, char *to)
{
    if(n == 1)
    {
        printf("1 %c %c\n",*from,*to);
        return;
    }
    hanoi(n-1,from,to,by);
    printf("%d %c %c\n",n,*from,*to);
    hanoi(n-1,by,from,to);
}
int main()
{
    int n;
    scanf("%d",&n);
    char a = 'A';
    char b = 'B';
    char c = 'C';
    hanoi(n,&a,&b,&c);
}
