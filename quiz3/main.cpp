#include <stdio.h>

long long fac(long long n)
{
    if(n ==1) return 1;
    return fac(n-1)*n;
}
int main()
{
    long long n;
    scanf("%lld",&n);
    printf("%lld",fac(n));
}
