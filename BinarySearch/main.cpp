#include <stdio.h>

int cnt=0;
int BSearch(int* arr,int len,int n)
{
    int first = 0;
    int last = len-1;
    while(first<=last)
    {
        int mid = (first+last)/2;
        if(arr[mid] == n)
            return mid;
        else if(arr[mid]>n)
        {
            last = mid-1;
        }
        else
        {
            first = mid+1;
        }
        cnt++;
    }
    return -1;
}
int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int idx;
    idx = BSearch(arr,sizeof(arr)/sizeof(int),7);

    if(idx == -1)
        printf("no data\n");
    else
        printf("data is here %d\n",idx);

    printf("%d",cnt);

    return 0;
}
