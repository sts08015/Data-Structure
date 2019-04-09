#ifndef LISTBASESTACK_H_INCLUDED
#define LISTBASESTACK_H_INCLUDED

#define TRUE 1
#define FALSE 0
typedef int Data;

typedef struct _node
{
    struct _node * next;
    Data data;
}Node;

typedef struct _listStack
{
    Node * head;
}ListStack;

typedef ListStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack *pstack);
void SPush(Stack * pstack,Data data);
Data SPop(Stack * pstack);
Data Speek(Stack * pstack);
#endif // LISTBASESTACK_H_INCLUDED
