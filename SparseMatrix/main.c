#include <stdio.h>
#define MAX_TERMS 10

typedef struct
{
    int row;
    int col;
    int value;
} element;

typedef struct _SparseMatrix
{
    element data[MAX_TERMS];
    int rows;
    int cols;
    int terms;
} SparseMatrix;

SparseMatrix sparse_matrix_add(SparseMatrix a, SparseMatrix b)
{
    SparseMatrix c;
    c.rows = a.rows;
    c.cols = a.cols;
    int chk = 0;
    int cnt = 0;
    for(int i=0;i<a.terms;i++)
    {
        c.data[cnt].col = a.data[i].col;
        c.data[cnt].row = a.data[i].row;
        c.data[cnt++].value = a.data[i].value;
    }
    for(int i=0;i<b.terms;i++)
    {
        chk = 0;
        for(int j=0;j<cnt;j++)
        {
            if(c.data[j].col == b.data[i].col && c.data[j].row == b.data[i].row)
            {
                chk = 1;
                c.data[j].value += b.data[i].value;
            }
        }
        if(!chk)
        {
            c.data[cnt].row = b.data[i].row;
            c.data[cnt].col = b.data[i].col;
            c.data[cnt++].value = b.data[i].value;
        }

    }
    c.terms = cnt;
    return c;
}
void SparseMatrix_print(SparseMatrix C)
{
    element tmp;

    for(int i=0;i<C.terms;i++)
    {
        for(int j=i;j<C.terms;j++)
        {
            if(C.data[i].row > C.data[j].row)
            {
                tmp = C.data[i];
                C.data[i] = C.data[j];
                C.data[j] = tmp;
            }
            else if(C.data[i].col > C.data[j].col)
            {
                tmp = C.data[i];
                C.data[i] = C.data[j];
                C.data[j] = tmp;
            }
        }
    }
    for(int i=0;i<C.terms;i++)
    {
        printf("%d %d %d ",C.data[i].row,C.data[i].col,C.data[i].value);
    }
}
int main()
{
    SparseMatrix a = { { { 1,1,5 },{ 2,2,9 } }, 3,3,2 };
    SparseMatrix b = { { { 0,0,5 },{ 2,2,9 } }, 3,3,2 };

    SparseMatrix a1 = { { { 1,1,5 },{ 2,2,9 },{0,0,7} }, 3,3,3 };
    SparseMatrix b1 = { { { 0,0,5 },{ 2,2,9 } }, 3,3,2 };

    SparseMatrix c;

    c = sparse_matrix_add(a, b);

    SparseMatrix_print(c);

    return 0;
}
