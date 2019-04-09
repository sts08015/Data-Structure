#include <stdio.h>
#include <stdlib.h>
#include "CLLBaseStack.h"
#include "../CLinkedList/CLinkedList.h"

void StackInit(Stack * pstack)
{
    pstack->plist = (List *)malloc(sizeof(List));
    ListInit(pstack->plist);
}
int SIsEmpty(Stack * pstack)
{
    if(pstack->plist->numOfData ==0) return TRUE;
    else return FALSE;
}
void SPush(Stack * pstack,Data data)
{
    LInsertFront(pstack->plist,data);
}
Data SPop(Stack * pstack)
{
    Data data;
    LFirst(pstack->plist,&data);
    LRemove(pstack->plist);
    return data;
}
Data SPeek(Stack * pstack)
{
    return pstack->plist->tail->next->data;
}
