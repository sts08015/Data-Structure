#ifndef DUMMYDBLINKEDLIST_H_INCLUDED
#define DUMMYDBLINKEDLIST_H_INCLUDED

#define TRUE 1
#define FALSE 0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
    struct _node * prev;
}Node;


typedef struct _dbDLinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
}DBDLinkedList;
typedef DBDLinkedList List;

void ListInit(List *plist);
void LInsert(List *plist,Data data);

int LFirst(List *plist,Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);
int LCount(List * plist);
Data LRemove(List * plist);
#endif // DUMMYDBLINKEDLIST_H_INCLUDED
