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
	if(pq->front==pq->rear)
		return TRUE;
	return FALSE;
}


void Enqueue(Queue * pq, Data data)
{
	if((pq->rear+2-pq->front)%QUE_LEN){	
		pq->rear=(pq->rear+1)%QUE_LEN;//떙기고 넣고 
		pq->queArr[pq->rear]=data;
	}
		
	else
		printf("error");
}

Data Dequeue(Queue * pq)
{
	
	
	if(pq->front==pq->rear){
		printf("Queue Memory Error!");
		exit(-1);
	}
	Data temp=pq->queArr[pq->front+1];
	if(pq->front+1==QUE_LEN) pq->front=0;
	else pq->front++;
	return temp;
}

Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("error");
		exit(-1);
	}
	
	if(pq->front+1==QUE_LEN)
		return pq->queArr[0];
	else
		return pq->queArr[pq->front+1]; 
	
}
