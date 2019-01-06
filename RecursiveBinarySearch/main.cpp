#include <stdio.h>

int BinarySearch(int *arr,int n,int first,int last)
{
    if(first>last) return -1;
    int mid = (first+last)/2;
    if(arr[mid]>n) return BinarySearch(arr,n,first,mid-1);
    else if(arr[mid]<n) return BinarySearch(arr,n,mid+1,last);
    else return mid;
}

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    int idx;
    idx = BinarySearch(arr,7,0,9);

    if(idx == -1) printf("not found");
    else printf("found here %d",idx);
}
