#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[30];
    scanf("%s",a);
    printf("%s\n",a);

    char * x;
    int n;
    scanf("%d",&n);
    x = (char *)malloc(n*sizeof(char));
    scanf("%s",x);
    printf("%s",x);
    free(x);
    return 0;
}
