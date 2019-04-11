#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

int GetOpPrec(char op)
{

}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if(op1Prec > op2Prec)
		return 1;
	else if(op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	char * convExp = (char*)malloc(expLen+1);

	int i, idx=0;
	char tok, popOp;

	memset(convExp, 0, sizeof(char)*expLen+1);
	StackInit(&stack);

	for(i=0; i<expLen; i++)
	{
		tok = exp[i];
		if(isdigit(tok))
		{

		}
		else
		{
			switch(tok)
			{
			case '(':

			case ')':

			case '+': case '-':
			case '*': case '/':

			}
		}
	}

	while(!SIsEmpty(&stack))
		convExp[idx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}
