#include <stdio.h>
#include <stdlib.h>
#include "CDLinkedList.h"


void ListInit(List * plist)
{
    plist->numOfData = 0;
    plist->before = NULL;
    plist->cur = NULL;
    plist->tail = (Node *)malloc(sizeof(Node));
}
void LInsert(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode ->data = data;

    if(plist->numOfData == 0)
    {
        plist->tail->next = newNode;
        newNode->next = plist->tail;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist->numOfData ==0) return FALSE;

    plist->cur = plist->tail->next;
    plist->before = plist->tail;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List * plist, Data * pdata)
{
    if(plist->numOfData == 0) return FALSE;

    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}
Data LRemove(List * plist)
{

}
int LCount(List * plist)
{
    return plist->numOfData;
}
