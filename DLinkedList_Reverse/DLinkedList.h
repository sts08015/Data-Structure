#ifndef DLINKEDLIST_H_INCLUDED
#define DLINKEDLIST_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _node
{
    LData data;
    struct _node* next;
}Node;

typedef struct _linkedList
{
    Node * head;
    Node * tail;
    Node * before;
    Node * cur;
    int numOfData;
    int (*comp)(LData d1,LData d2);
}List;

void ListInit(List * plist);
void LInsert(List * plist,LData data);
int LFirst(List * plist, LData * pdata);
int LNext(List * plist,LData * pdata);
LData LRemove(List * plist);
int LCount(List * plist);
#endif // DLINKEDLIST_H_INCLUDED
