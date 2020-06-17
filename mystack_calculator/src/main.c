#include "PostfixCalc.h"

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

PostfixCalc* calc = NULL;

int main(int argc, char *argv[])
{
    if (argc > 2)
    {
        printf("Too many arguments supplied.\n");
        return 0;
    }
    else if (argc < 2)
    {
        printf("One argument expected.\n");
        return 0;
    }

    const char* postfix = argv[1];
    calc = InitializePostfixCalc();
    double answer = 0;

    Calculate(calc, postfix, strlen(postfix), &answer);

    printf("For the input %s the solution is %lf\n", argv[1], answer);

    DestroyPostfixCalc(&calc);

    return 0;
}
