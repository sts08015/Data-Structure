#ifndef NAMECARD_C_INCLUDED
#define NAMECARD_C_INCLUDED
#include "NameCard.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

NameCard * MakeNameCard(char * name,char *phone)
{
    NameCard* namecard = (NameCard *)malloc(sizeof(NameCard));
    //NameCard namecard;
    strcpy(namecard->name,name);
    strcpy(namecard->phone,phone);
    return namecard;
}

void ShowNameCardInfo(NameCard * pcard)
{
    printf("Name : %s\n",pcard->name);
    printf("TEL : %s\n",pcard->phone);
}

int NameCompare(NameCard * pcard,char * name)
{
    if(strcmp(pcard->name,name) == 0) return 0;
    else return 1;
}

void ChangePhoneNum(NameCard * pcard,char * phone)
{
    strcpy(pcard->phone,phone);
}
#endif // NAMECARD_C_INCLUDED
