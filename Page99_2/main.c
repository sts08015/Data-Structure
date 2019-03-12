#include <stdio.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
    List list;
    ListInit(&list);
    NameCard * namecard1 = MakeNameCard("fisma","010");
    NameCard * namecard2 = MakeNameCard("hello","011");
    NameCard * namecard3 = MakeNameCard("world","070");

    LInsert(&list,namecard1);
    LInsert(&list,namecard2);
    LInsert(&list,namecard3);

    NameCard * tmp;

    if(LFirst(&list,&tmp))
    {
        ShowNameCardInfo(tmp);
        while(LNext(&list,&tmp))
        {
            ShowNameCardInfo(tmp);
            puts("");
        }
    }
    printf("Finding fisma...\n");
    if(LFirst(&list,&tmp))
    {
        if(!NameCompare(tmp,"fisma"))
        {
            ShowNameCardInfo(tmp);
            puts("");
        }
        while(LNext(&list,&tmp))
        {
            if(!NameCompare(tmp,"fisma"))
            {
                ShowNameCardInfo(tmp);
                puts("");
            }
        }
    }
    printf("Changing hello...\n");
    if(LFirst(&list,&tmp))
    {
        if(!NameCompare(tmp,"hello"))
        {
            ChangePhoneNum(tmp,"777");
            ShowNameCardInfo(tmp);
            puts("");
        }
        while(LNext(&list,&tmp))
        {
            if(!NameCompare(tmp,"hello"))
            {
                ChangePhoneNum(tmp,"777");
                ShowNameCardInfo(tmp);
                puts("");
            }
        }
    }

    printf("Removing world...\n");
    if(LFirst(&list,&tmp))
    {
        if(!NameCompare(tmp,"world"))
        {
            LRemove(&list);
        }
        while(LNext(&list,&tmp))
        {
            if(!NameCompare(tmp,"world"))
            {
                LRemove(&list);
            }
        }
    }
    //printf("22");

    if(LFirst(&list,&tmp))
    {
        ShowNameCardInfo(tmp);
        while(LNext(&list,&tmp))
        {
            ShowNameCardInfo(tmp);
            //puts("");
            free(tmp);
        }
    }
}
