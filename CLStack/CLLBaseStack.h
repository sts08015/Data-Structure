#ifndef CLLBASESTACK_H_INCLUDED
#define CLLBASESTACK_H_INCLUDED
#include "../CLinkedList/CLinkedList.h"

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _listStack
{
    List *plist;

}ListStack;

typedef ListStack Stack;


void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack,Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);
#endif // CLLBASESTACK_H_INCLUDED
