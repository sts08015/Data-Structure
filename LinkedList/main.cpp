#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main()
{
    Node * head = 0;
    Node * tail = 0;
    Node * cur = 0;

    Node * newNode = 0;
    int num;

    while(true)
    {
        printf("input numbers : ");
        scanf("%d",&num);
        if(num<=0) break;

        newNode = (Node *)malloc(sizeof(Node));
        newNode->data = num;
        newNode->next = 0;

        if(head == 0)
        {
            //head = newNode;
            tail = newNode;
        }
        else
        {
            //tail->next = newNode;
            newNode->next = head;
        }

        //tail = newNode;
        head = newNode;
    }

    printf("\n\nThis is the elements\n");
    cur = head;
    if(cur == 0) puts("no elements");
    else
    {
        do
        {
            printf("%d ",cur->data);
            cur = cur->next;
        }
        while(cur!=0);

        printf("\ndeleting elements....\n");

        while(true)
        {
            Node * rNode = head;
            Node * rNextNode = head->next;
            if(rNode == 0) break;

            printf("%d is deleted\n",head->data);
            free(rNode);
            head = rNextNode;
        }
    }
    return 0;
}
