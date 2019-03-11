#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	List list;
	int data;
	aa();

	ListInit(&list);


	LInsert(&list, 11);  LInsert(&list, 11);
	LInsert(&list, 22);  LInsert(&list, 22);
	LInsert(&list, 33);

	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))    // ù ��° ������ ��ȸ
	{
		printf("%d ", data);

		while(LNext(&list, &data))    // �� ��° ������ ������ ��ȸ
			printf("%d ", data);
	}
	printf("\n\n");

	/*** ���� 22�� Ž���Ͽ� ��� ���� ***/
	if(LFirst(&list, &data))
	{
		if(data == 22)
			LRemove(&list);

		while(LNext(&list, &data))
		{
			if(data == 22)
				LRemove(&list);
		}
	}

	/*** ���� �� ����� ������ ��ü ��� ***/
	printf("���� �������� ��: %d \n", LCount(&list));

	if(LFirst(&list, &data))
	{
		printf("%d ", data);

		while(LNext(&list, &data))
			printf("%d ", data);
	}
	printf("\n\n");
	return 0;
}
