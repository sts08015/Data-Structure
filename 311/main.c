#include <stdio.h>
#include "ArrayList.h"

int main(void)
{
	/*** ArrayList의 생성 및 초기화 ***/
	List list;
	ListInit(&list);

	for(int i=1;i<=9;i++) LInsert(&list,i);

	int hap =0;
	int a = LFirst(&list,&hap);

	while(LNext(&list,&a)) hap+=a;
	printf("Sum : %d\n",hap);

	if(LFirst(&list,&a))
	{
		if(a%2==0 || a%3==0) hap = LRemove(&list);
		while(LNext(&list,&a))
		{
			if(a%2==0 || a%3==0) hap = LRemove(&list);
		}
	}

	if(LFirst(&list,&a))
	{
		printf("LeftOver Data : %d ",a);
		while(LNext(&list,&a)) printf("%d ",a);
	}

}
// linked list solve
