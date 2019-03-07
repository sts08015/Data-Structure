#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d",&n);
    //int * arr = (int*)malloc(n*sizeof(int));
    int arr[110];
    for(int i = 0;i<n;i++) scanf("%d",arr+i);

    for(int i=0;i<n;i++)
    {
        for(int j = i;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                int tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }

    if(n%2 ==0)
    {
        //printf("kdfja;fdf;kja");
        double ans;
        //printf("%d %d\n",arr[n/2],arr[n/2 -1]);
        ans = (double)(arr[n/2]+arr[n/2 -1])/2;
        printf("%g",ans);
    }

    else{
        printf("%d",arr[(n-1)/2]);
    }
    //free(arr);
    return 0;
}
