#ifndef __C_QUEUE_H__
#define __C_QUEUE_H__

#define TRUE	1
#define FALSE	0


typedef int Data;

int QUE_LEN[] = {50,100,150,200,250};

typedef struct _cQueue
{
	int front;
	int rear;
	Data* queArr;
} CQueue;

typedef CQueue Queue;


void ChooseSize(int a);
void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif
