#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"

void StackInit(Stack * pstack)
{
    pstack->head = NULL;
}
int SIsEmpty(Stack *pstack)
{
    if(pstack->head == NULL) return TRUE;
    else return FALSE;
}
void SPush(Stack * pstack,Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if(pstack->head == NULL) pstack->head = newNode;
    else
    {
        newNode->next = pstack->head;
        pstack->head = newNode;
    }
}
Data SPop(Stack * pstack)
{
    Node * rNode = pstack->head;
    if(SIsEmpty(pstack))
    {
        puts("Memory Error");
        exit(-1);
    }

    Data rData = pstack->head->data;
    pstack->head = pstack->head->next;
    free(rNode);
    return rData;
}
Data SPeek(Stack * pstack)
{
    return pstack->head->data;
}
