#include <stdio.h>
#define MAX_DEGREE 101
//계수와 차수를 세트로 줄는 방법?

typedef struct{
    int degree;
    float coef[MAX_DEGREE];
}polynomial;

void poly_print(polynomial C)
{
    int i=0;
    int tmp = C.degree;
    while(1)
    {
        if(C.coef[i]!=0) break;
        i++;
        tmp--;
    }
    if(tmp>=0)printf("%d ",tmp);
    if(tmp<0) printf("%d %d",0,0);
    for(int k=i;k<=C.degree;k++)
        printf("%g ",C.coef[k]);

}

polynomial poly_add(polynomial A,polynomial B)
{
    polynomial C;
    C.degree = (A.degree>B.degree)? A.degree:B.degree;
    int i =0;
    int j = 0;
    for(int k=0;k<=C.degree;k++)
    {
        if(A.degree == B.degree)
        {
            C.coef[k] = A.coef[i] + B.coef[j];
            A.degree--;
            B.degree--;
            i++;
            j++;
        }
        else if(A.degree > B.degree)
        {
            C.coef[k] = A.coef[i];
            A.degree--;
            i++;
        }
        else{
            C.coef[k] = B.coef[j];
            B.degree--;
            j++;
        }
    }
    return C;
}

int main()
{
    polynomial a = {5,{3,6,0,0,1,10}};
    polynomial b = {5,{-3,-6,0,0,0,-10}};
    polynomial c;
    c = poly_add(a,b);
    poly_print(c);
    return 0;
}
