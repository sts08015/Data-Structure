#include <stdio.h>
#include "DBLinkedList.h"

int main(void)
{
	// 양방향 연결 리스트의 생성 및 초기화  ///////
	List list;
	int data;
	ListInit(&list);

	// 8개의 데이터 저장  ///////
	LInsertFront(&list, 1);  LInsertRear(&list, 2);
	LInsertFront(&list, 3);  LInsertRear(&list, 4);
	LInsertFront(&list, 5);  LInsertRear(&list, 6);
	LInsertFront(&list, 7);  LInsertRear(&list, 8);

	// 저장된 데이터의 조회  ///////
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
