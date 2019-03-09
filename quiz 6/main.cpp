#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void palin(char *a,int start,int end)
{
    if(start>end)
    {
        printf("yes");
        return;
    }
    if(a[start]!=a[end])
    {
        printf("no");
        exit(0);
    }
    palin(a,start+1,end-1);
}
int main()
{
    char a[100];
    //gets(a);
    fgets(a,sizeof(a),stdin);
    int len = strlen(a)-1;
    palin(a,0,len-1);
}
