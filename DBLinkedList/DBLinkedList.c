#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"
 // dummy 모두 없는거, 양쪽에 있는거 , 한쪽에 있는거
void ListInit(List * plist)
{
    plist->head = NULL;
    //plist->head->prev = NULL;
    plist->numOfData = 0;
    plist->tail = NULL;
    //plist->tail->next = NULL;
}
void LInsertFront(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->head == NULL)
    {
        plist->head = newNode;
        plist->tail = plist->head;
    }
    else
    {
        newNode->next = plist->head;
        plist->head->prev = newNode;
        plist->head = newNode;
    }
    (plist->numOfData)++;
}
void LInsertRear(List * plist, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        plist->head = plist->tail;
    }
    else
    {
        plist->tail->next = newNode;
        newNode->prev = plist->tail;
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist->numOfData == 0) return FALSE;
    plist->cur = plist->head;
    *pdata = plist->cur->data;
    return TRUE;
}
int LNext(List * plist, Data * pdata)
{
    if(plist->cur == plist->tail) return FALSE;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}
int LPrevious(List * plist, Data * pdata)
{
    if(plist->cur == plist->head) return FALSE;
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    return TRUE;
}

int LCount(List * plist)
{
    return plist->numOfData;
}

Data LRemove(List * plist)
{
    Node * rNode = plist->cur;
    Data rData = plist->cur->data;

    if(plist->cur == plist->head)
    {
        plist->head = plist->cur->next;
        //plist->head->prev = NULL;
        //plist->cur = plist->head->prev;
    }
    else if(plist->cur == plist->tail)
    {
        plist->tail = plist->cur->prev;
        //plist->tail->next = NULL;
        //plist->cur = plist->tail;
    }
    else
    {
        plist->cur->prev->next = plist->cur->next;
        plist->cur->next->prev = plist->cur->prev;
        //plist->cur = plist->cur->prev;
    }
    free(rNode);
    (plist->numOfData)--;
    return rData;
}
