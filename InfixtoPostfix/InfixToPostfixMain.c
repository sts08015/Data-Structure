#include <stdio.h>
#include "InfixToPostfix.h"

int main(void)
{
	char exp1[] = "1+2*3";
	char exp2[] = "(1+2)*3";
	char exp3[] = "((1-2)+3)*(5-2)";
	char exp4[] = "4/(1+3)+1";
	char exp5[] = "(1+2)/(2-1)";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);
	ConvToRPNExp(exp4);
	ConvToRPNExp(exp5);

	printf("%s \n", exp1);
	printf("%s \n", exp2);
	printf("%s \n", exp3);
	printf("%s \n", exp4);
	printf("%s \n", exp5);
	return 0;
}
