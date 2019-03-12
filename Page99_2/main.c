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
        }
    }


}
