#include <stdio.h>
#include "NameCard.h"
#include <string.h>

NameCard *MakeNameCard(char * name, char* phone)
{
    NameCard* namecard = (NameCard*)malloc(sizeof(NameCard));
    strcpy(namecard->name,name);
    strcpy(namecard->phone,phone);
    return namecard;
}
void ShowNameCardInfo(NameCard *pcard)
{
    printf("[이름] %s\n",pcard->name);
    printf("[번호] %s\n",pcard->phone);
}

int NameCompare(NameCard * pcard,char * name)
{
    return strcmp(pcard->name,name);
}

void ChangePhoneNum(NameCard * pcard,char * phone)
{
    strcpy(pcard->phone,phone);
}
