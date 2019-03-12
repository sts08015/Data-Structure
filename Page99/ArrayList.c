#include <stdio.h>
#include "ArrayList.h"

void ListInit(List * plist)
{
	plist->curPosition = -1;
	plist->numOfData = 0;
}

void LInsert(List * plist, LData data)
{
	if(plist->numOfData>=LIST_LEN) return;

	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List * plist, LData * pdata)
{
	if(plist->numOfData == 0) return 0;
	plist->curPosition = 0;

	*pdata = plist->arr[0];
	//printf("1");
	return 1;
}

int LNext(List * plist, LData * pdata)
{
	if(plist->curPosition>=plist->numOfData-1) return FALSE;
	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];
	return TRUE;
}

LData LRemove(List * plist)
{
	int cur = plist->curPosition;
	int len = plist->numOfData;
	LData data = plist->arr[cur];
    for(int i=cur;i<len;i++) plist->arr[i] = plist->arr[i+1];
    (plist->curPosition)--;
    (plist->numOfData)--;
    return data;
}

int LCount(List * plist)
{
	return plist->numOfData;
}
