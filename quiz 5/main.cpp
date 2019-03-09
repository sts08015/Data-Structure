#include <stdio.h>
#include <string.h>

int main()
{
    char a[100];
    //gets(a);
    fgets(a,sizeof(a),stdin);
    int len = strlen(a);
    int i = 0;
    int j = len-2;
    int chk = 0;
    while(i<=j)
    {
        if(a[i]!=a[j])
        {
            printf("no");
            chk = 1;
            break;
        }
        i++;
        j--;
    }
    if(chk == 0) printf("yes");
}
