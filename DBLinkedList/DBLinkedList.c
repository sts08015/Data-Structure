#include <stdio.h>
#include "DBLinkedList.h"
 // dummy 모두 없는거, 양쪽에 있는거 , 한쪽에 있는거
void ListInit(List * plist)
{
    plist->numOfData = 0;
    plist->head = NULL;
    //plist->head->next = NULL;
    plist->tail = NULL;
    plist->cur = NULL;
}
void LInsertFront(List * plist, Data data)
{
    Node* newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;

    if(plist->head == NULL)
    {
        plist->head = newNode;
        plist->tail = newNode;
    }
    else
    {

    }
}
void LInsertRear(List * plist, Data data)
{

}

int LFirst(List * plist, Data * pdata)
{

}
int LNext(List * plist, Data * pdata)
{

}
int LPrevious(List * plist, Data * pdata)
{

}

int LCount(List * plist)
{
    return plist->numOfData;
}
