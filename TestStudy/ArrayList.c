#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
   plist->numOfData = 0;
   plist->tail = (Node *)malloc(sizeof(Node));
   plist->tail->next = plist->tail;
   plist->before = NULL;
   plist->cur = NULL;
}
void LInsert(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
    plist->tail = newNode;
    (plist->numOfData)++;
}
void LInsertFront(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    newNode->next = plist->tail->next->next;
    plist->tail->next->next = newNode;
    (plist->numOfData)++;
}
int LFirst(List * plist, Data * pdata)
{
    if(plist->numOfData == 0) return FALSE;

    plist->cur = plist->tail->next->next;
    plist->before = plist->tail->next;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List * plist, Data * pdata)
{
    if(plist->numOfData == 0) return FALSE;

    if(plist->cur == plist->tail) plist->cur = plist->cur->next;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}
Data LRemove(List * plist)
{
    Node * rNode = (Node *)malloc(sizeof(Node));
    Data data = rNode->data;
    if(plist->cur == plist->tail)
    {
        plist->tail = plist->before;
    }
    plist->before->next = plist->cur->next;

    free(rNode);
    (plist->numOfData)--;
    return data;
}
int LCount(List * plist)
{
    return plist->numOfData;
}
