#include <stdio.h>
#include "ArrayStack.h"

void StackInit(Stack * pstack)
{
    pstack->topIndex = -1;
}
int SIsEmpty(Stack * pstack)
{
    if(pstack->topIndex == -1) return TRUE;
    else return FALSE;
}
void SPush(Stack * pstack,Data data)
{
    if(pstack->topIndex == STACK_LEN-1) puts("cannot push!!");
    else
    {
        pstack->stackArr[++(pstack->topIndex)] = data;
    }
}
Data SPop(Stack * pstack)
{
    Data popData = pstack->stackArr[pstack->topIndex];
    pstack->stackArr[pstack->topIndex] = 0;
    (pstack->topIndex)--;
    return popData;
}
Data SPeek(Stack * pstack)
{
    return pstack->stackArr[pstack->topIndex];
}
