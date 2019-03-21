#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

void ListInit(List * plist)
{
    plist->head = (Node *)malloc(sizeof(Node));
    plist ->numOfData = 0;
    plist ->comp = NULL;
    plist->head->next = NULL;
    plist->tail = plist->head;
}

void LInsert(List * plist,LData data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode -> data = data;
    newNode -> next = NULL; // important!!!!
    //newNode ->next = plist->head->next;
    //plist->head->next = newNode;
    plist->tail->next = newNode;
    plist->tail = newNode;
    (plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
    if(plist->numOfData <=0) return FALSE;
    plist->cur = plist->head->next;
    plist->before = plist->head;

    *pdata = (plist->cur->data);
    return TRUE;
}
int LNext(List *plist,LData *pdata)
{
    if(plist->cur->next == NULL) return FALSE;
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    return TRUE;
}
LData LRemove(List *plist)
{
    Node * rNode = plist->cur;
    LData rData = rNode->data;
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    (plist->numOfData)--;
    free(rNode);
    return rData;
}
int LCount(List * plist)
{
    return plist->numOfData;
}
