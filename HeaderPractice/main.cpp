#include <stdio.h>
#include "stdiv2.h"
#include "intdiv4.h"

int main()
{
    Div val = IntDiv(5,2);
    printf("¸ò : %d \n", val.quotient);
    printf("³ª¸ÓÁö : %d",val.remainder);
    return 0;
}
