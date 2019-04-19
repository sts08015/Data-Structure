#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CircularQueue.h"

#define CUS_COME_TERM 15

#define CHE_BUR 0
#define BUL_BUR 1
#define DUB_BUR 2

#define CHE_TERM 12
#define BUL_TERM 15
#define DUB_TERM 24

int main()
{
    int makeProc = 0;
    Queue que;
    QueueInit(&que);
    srand(time(NULL));

    for(int sec=0;sec<3600;sec++)
    {
        if(sec % CUS_COME_TERM == 0)
        {
            switch(rand()%3)
            {
            case CHE_BUR:
                Enqueue(&que,CHE_TERM);
                break;
            case BUL_BUR:
                Enqueue(&que,BUL_TERM);
                break;
            case DUB_BUR:
                Enqueue(&que,DUB_TERM);
                break;
            }
        }
        if(makeProc == 0 && !QIsEmpty(&que))
            makeProc = Dequeue(&que);
        makeProc--;
    }
}
