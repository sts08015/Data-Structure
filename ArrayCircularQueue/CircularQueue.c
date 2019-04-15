#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

void QueueInit(Queue * pq)
{
    pq->front = 0;
    pq->rear = 0;
}
int QIsEmpty(Queue * pq)
{
    if(pq->front == pq->rear) return TRUE;
    else return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
    if((pq->front+QUE_LEN-pq->rear)%QUE_LEN == 1) puts("cannot enqueue!!");  // think of modular idea!!!
    else
    {
        pq->rear = ((pq->rear)+1)%QUE_LEN;
        pq->queArr[pq->rear] = data;
    }
}
Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        puts("cannot dequeue!!");
        exit(0);
    }
    else
    {
        Data rData = pq->queArr[((pq->front)+1)%QUE_LEN];
        pq->queArr[((pq->front)+1)%QUE_LEN] = 0;
        pq->front = ((pq->front)+1)%QUE_LEN;
        return rData;
    }
}
Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        puts("no data!!");
        exit(0);
    }
    else return pq->queArr[((pq->front)+1)%QUE_LEN];
}
