#include <stdio.h>

int main()
{
    int tmp;
    int a[] = {1,3,-1,6,7,8,9,10,4,0};
    for(int i=0;i<sizeof(a)/4;i++){
        for(int j=i;j<sizeof(a)/4;j++){
          if(a[i]<a[j]){
            tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
          }
        }
    }
    for(int i : a)
        printf("%d ",i);
}
