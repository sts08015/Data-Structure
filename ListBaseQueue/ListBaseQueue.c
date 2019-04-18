#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}
int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}
void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    if(pq->front == NULL)
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}
Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        puts("cannot dequeue!!!");
        exit(0);
    }
    else
    {
        Data rData = pq->front->data;
        Node * rNode = pq->front;
        if(pq->front == pq->rear)
        {
            pq->front = NULL;
            pq->rear = NULL;
        }
        else
        {
            pq->front = pq->front->next;
            free(rNode);
        }
        return rData;
    }
}
Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
        exit(0);
    return pq->front->data;
}
