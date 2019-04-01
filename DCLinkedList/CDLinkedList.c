#include <stdio.h>
#include <stdlib.h>
#include "CDLinkedList.h"

// how to improve
// 1. move tail
// idea : next next
// wlqudgus's idea
void ListInit(List * plist)
{
    plist->numOfData = 0;
    plist->before = NULL;
    plist->cur = NULL;
    plist->tail = (Node *)malloc(sizeof(Node));
    plist->tail->next = plist->tail;
}
void LInsert(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));


    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
    plist->tail->data = data;
    plist->tail = plist->tail->next;
    (plist->numOfData)++;
}
void LInsertFront(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode ->data = data;
    newNode->next = plist->tail->next;
    plist->tail->next = newNode;
    (plist->numOfData)++;
}
int LFirst(List * plist, Data * pdata)
{
    if(plist->numOfData ==0)
        return FALSE;

    plist->cur = plist->tail->next;
    plist->before = plist->tail;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List * plist, Data * pdata)
{
    if(plist->numOfData == 0)
        return FALSE;

    if(plist->cur->next == plist->tail)
    {
        plist->before = plist->tail;
        plist->cur = plist->tail->next;
    }
    else
    {
        plist->before = plist->cur;
        plist->cur = plist->cur->next;
    }
    *pdata = plist->cur->data;
    return TRUE;
}
Data LRemove(List * plist)
{
    Node * rNode = plist->cur;
    Data rData = plist->cur->data;

    plist->before->next = plist->cur->next;
    (plist->numOfData)--;
    plist->cur = plist->before;
    free(rNode);
    return rData;
}
int LCount(List * plist)
{
    return plist->numOfData;
}
