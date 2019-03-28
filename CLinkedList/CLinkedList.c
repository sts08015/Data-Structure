#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

void ListInit(List * plist)
{
    plist->numOfData = 0;
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
}
void LInsert(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}
void LInsertFront(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
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
    if(plist->tail == NULL) return FALSE;

    plist->before = plist->tail;
    plist->cur = plist->before->next;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List * plist, Data * pdata)
{
    if(plist->tail == NULL) return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}
Data LRemove(List * plist)
{
    Node * rNode = plist->cur;
    Data rData = rNode->data;
        // think when numOfdata is 0
    if(rNode == plist->tail)
    {
        if(plist->tail == plist->tail->next) plist->tail = NULL;
        else plist->tail = plist->before;
    }
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    free(rNode);
    (plist->numOfData)--;
    return rData;
}
int LCount(List * plist)
{
    return plist->numOfData;
}
