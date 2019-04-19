#include <stdio.h>
#include "CDLinkedList.h"
#include "Employee.h"
#include <string.h>
#include <stdlib.h>

int main(void)
{
    // ���� ���� ����Ʈ�� ���� �� �ʱ�ȭ ///////
    List list;
    int data, i, nodeNum;
    ListInit(&list);
    /*Employee * pemp;
    pemp = (Employee *)malloc(sizeof(Employee));
    strcpy(pemp->name,"Terry");
    pemp->num = 111;
    LInsert(&list,pemp);

    strcpy(pemp->name,"Harry");
    pemp->num = 222;
    LInsert(&list,pemp);

    strcpy(pemp->name,"Sunny");
    pemp->num = 333;
    LInsert(&list,pemp);
*/
    // ����Ʈ�� 5���� �����͸� ���� ///////
    LInsert(&list, 3);
	LInsert(&list, 4);
	LInsert(&list, 5);
	LInsertFront(&list, 2);
	LInsertFront(&list, 1);
    LInsertFront(&list, 2);
    LInsertFront(&list, 1);

    // ����Ʈ�� ����� �����͸� ���� 3ȸ ��� ///////
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        for(i=0; i<LCount(&list)*3-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    printf("\n");

    // 2�� ����� ã�Ƽ� ��� ���� ///////
    nodeNum = LCount(&list);

    if(nodeNum != 0)
    {
        LFirst(&list, &data);
        if(data%2 == 0)
            LRemove(&list);

        for(i=0; i < nodeNum-1; i++)
        {
            LNext(&list, &data);
            if(data%2 == 0)
                LRemove(&list);
        }
    }

    // ��ü ������ 1ȸ ��� ///////
    if(LFirst(&list, &data))
    {
        printf("%d ", data);

        for(i=0; i<LCount(&list)-1; i++)
        {
            if(LNext(&list, &data))
                printf("%d ", data);
        }
    }
    return 0;
}
