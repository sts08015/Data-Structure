#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "InfixToPostfix.h"
#include "ListBaseStack.h"


int GetOpPrec(char op)
{
    switch(op)
    {
    case '*':
    case '/':
        return 5;
    case '+':
    case '-':
        return 3;
    case '(':
        return 1;
    }
    return -1;
}

int WhoPrecOp(char op1,char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);

    if(op1Prec>op2Prec)
        return 1;
    else if(op1Prec<op2Prec)
        return -1;
    else
        return 0;
}
void ConvToRPNExp(char exp[])
{
    Stack stack;
    StackInit(&stack);

    int i,idx = 0;
    char popOp,tok;

    int explen = strlen(exp);
    char* convExp = (char *)malloc(sizeof(char)*explen+1);
    memset(convExp,0,explen+1);


    for(i=0; i<explen; i++)
    {
        tok = exp[i];
        if(isdigit(tok))
            convExp[idx++] = tok;
        else
        {
            switch(tok)
            {
            case '+':
            case '-':
            case '*':
            case '/':
                while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack),tok)>=0)
                    popOp = SPop(&stack);
                convExp[idx++] = popOp;
                SPush(&stack,tok);
                break;
            case '(':
                SPush(&stack,tok);
                break;
            case ')':
                while(!SIsEmpty(&stack))
                {
                    popOp = SPop(&stack);
                    if(popOp == '(')
                        break;
                    convExp[idx++] = popOp;
                }
                break;
            }
        }
    }

    while(!SIsEmpty(&stack))
    {
        popOp = SPop(&stack);
        convExp[idx++] = popOp;
    }
    strcpy(exp,convExp);
    free(convExp);
}
