#include <stdio.h>
#include <stdlib.h>
#include "ArrayStack.h"
int main()
{
    Stack stack;
    StackInit(&stack);

    SPush(&stack,1);
    SPush(&stack,2);
    SPush(&stack,3);
    SPush(&stack,4);
    SPush(&stack,5);

    //printf("%d\n",SPeek(&stack));

    while(!SIsEmpty(&stack))
    {
        printf("%d ",SPeek(&stack));
        printf("%d\n",SPop(&stack));
        //printf("%d %d\n",SPop(&stack),SPeek(&stack));  -> printf는 뒤에부터 연산한다 ?!!!
    }

    return 0;
}
