#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// ����� ���� ����Ʈ�� ���� �� �ʱ�ȭ  ///////
	List list;
	int data;
	ListInit(&list);

	// 8���� ������ ����  ///////
	LInsertFront(&list, 1);  LInsertRear(&list, 2);
	LInsertFront(&list, 3);  LInsertRear(&list, 4);
	LInsertFront(&list, 5);  LInsertRear(&list, 6);
	LInsertFront(&list, 7);  LInsertRear(&list, 8);

	// ����� �������� ��ȸ  ///////
	if(LFirst(&list, &data))
	{
		printf("%d ", data);

		while(LNext(&list, &data)) 
			printf("%d ", data);
		
		while(LPrevious(&list, &data))
			printf("%d ", data);
		
		printf("\n\n");
	}

	return 0;
}
