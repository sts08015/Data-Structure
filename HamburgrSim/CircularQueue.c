#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CircularQueue.h"
int len;

void ChooseSize(int a)
{
	if(a>4) puts("choose small integer!!");
	len = QUE_LEN[a];
}
void QueueInit(Queue * pq)
{
	pq->front = 0;
	pq->rear = 0;
	pq->queArr = (Data *)malloc(sizeof(Data)*len);
	memset(pq->queArr,0,len);
}

int QIsEmpty(Queue * pq)
{
	if(pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}

int NextPosIdx(int pos)
{
	if(pos == len-1)
		return 0;
	else
		return pos+1;
}

void Enqueue(Queue * pq, Data data)
{
	if(NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);
	pq->queArr[pq->rear] = data;
}

Data Dequeue(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	pq->front = NextPosIdx(pq->front);
	return pq->queArr[pq->front];
}

Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->queArr[NextPosIdx(pq->front)];
}
