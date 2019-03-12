#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main()
{
    List list;
    ListInit(&list);

    NameCard* namecard1 = MakeNameCard("fisma","010");
    NameCard* namecard2 = MakeNameCard("hello","011");
    NameCard* namecard3 = MakeNameCard("world","070");


    LInsert(&list,*namecard1);
    LInsert(&list,*namecard2);
    LInsert(&list,*namecard3);

    NameCard tmp;
    // NameCard * tmp = NULL; Not Working !!!

    if(LFirst(&list,&tmp))
    {
        ShowNameCardInfo(&tmp);
        while(LNext(&list,&tmp))
        {
            ShowNameCardInfo(&tmp);
        }
    }

    char * a = "fisma";
    //char * newName ="FisMA";
    char * newNumber = "123";

    if(LFirst(&list,&tmp))
    {
        if(!NameCompare(&tmp,a))
        {
            printf("\n[[Found!!!]]\n");
            ShowNameCardInfo(&tmp);
            ChangePhoneNum(&tmp,newNumber);
            printf("\n[[Changed!!!!]]\n");
            ShowNameCardInfo(&tmp);
            LRemove(&list);
        }
        while(LNext(&list,&tmp))
        {
            if(!NameCompare(&tmp,a))
            {
                printf("\nFound!!!");
                ShowNameCardInfo(&tmp);
                printf("\n[[Changed!!!!]]\n");
                ShowNameCardInfo(&tmp);
                LRemove(&list);
            }
        }
    }

    printf("\n\n[[Removed!!!]]\n");
    if(LFirst(&list,&tmp))
    {
        ShowNameCardInfo(&tmp);
        while(LNext(&list,&tmp))
        {
            ShowNameCardInfo(&tmp);
        }
    }

    return 0;
}
