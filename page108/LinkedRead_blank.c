#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(void)
{
    Node * head = NULL;    // NULL 포인터 초기화
    Node * tail = NULL;
    Node * cur = NULL;
    Node * newNode = NULL;
    int readData;

    /**** 데이터를 입력 받는 과정 ****/
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    tail = (Node *)malloc(sizeof(Node));
    tail->next = NULL;
    //tail = head;
    //head = tail;
    cur = tail;
    while(1)
    {
        printf("자연수 입력: ");
        scanf("%d", &readData);
        if(readData < 1)
		{
			head->next = cur;
			break;
		}

        /*** 노드의 추가과정 ***/
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

		newNode->next = cur;
		cur = newNode;
    }
    printf("\n");

    /**** 입력 받은 데이터의 출력과정 ****/
    printf("입력 받은 데이터의 전체출력! \n");
    cur = head;
    if(head->next == tail) printf("no data\n");

    else
    {
        while(cur->next!=tail)
        {
            cur = cur->next;
            printf("%d ",cur->data);
        }
    }
    printf("\n\n");

    /**** 메모리의 해제과정 ****/
    Node * delNode = head;
    Node * delNextNode = head->next;

    if(delNextNode == tail) return 0;
    while(delNextNode != tail)
    {
        delNode = delNextNode;
        delNextNode = delNextNode->next;

        printf("deleting %d...\n",delNode->data);
        free(delNode);
    }


    return 0;
}
