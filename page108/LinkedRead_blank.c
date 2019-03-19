#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(void)
{
    Node * head = NULL;    // NULL ������ �ʱ�ȭ
    Node * tail = NULL;
    Node * cur = NULL;
    Node * newNode = NULL;
    int readData;

    /**** �����͸� �Է� �޴� ���� ****/
    head = (Node *)malloc(sizeof(Node));
    head->next = NULL;
    tail = (Node *)malloc(sizeof(Node));
    tail->next = NULL;
    //tail = head;
    //head = tail;
    cur = tail;
    while(1)
    {
        printf("�ڿ��� �Է�: ");
        scanf("%d", &readData);
        if(readData < 1)
		{
			head->next = cur;
			break;
		}

        /*** ����� �߰����� ***/
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;

		newNode->next = cur;
		cur = newNode;
    }
    printf("\n");

    /**** �Է� ���� �������� ��°��� ****/
    printf("�Է� ���� �������� ��ü���! \n");
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

    /**** �޸��� �������� ****/
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
