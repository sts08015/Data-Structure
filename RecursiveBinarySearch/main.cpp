#include <stdio.h>

int BinarySearch()
{

}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int idx;
    idx = BinarySearch();

    if(idx == -1) printf("not found");
    else printf("found here %d",idx);
}
