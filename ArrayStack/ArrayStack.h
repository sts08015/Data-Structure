#ifndef ARRAYSTACK_H_INCLUDED
#define ARRAYSTACK_H_INCLUDED

typedef int Data;

#define STACK_LEN 100
#define TRUE 1
#define FALSE 0

typedef struct _ArrayStack
{
   Data stackArr[STACK_LEN];
   int topIndex;

}ArrayStack;

typedef ArrayStack Stack;


void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);
void SPush(Stack * pstack,Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);
#endif // ARRAYSTACK_H_INCLUDED
