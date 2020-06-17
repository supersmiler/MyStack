#ifndef POSTFIXCALC_H
#define POSTFIXCALC_H

#include <stddef.h>

typedef struct
{
    int stackHandle;
    double answer;
} PostfixCalc;

PostfixCalc* InitializePostfixCalc();
void DestroyPostfixCalc(PostfixCalc**);

int Calculate(PostfixCalc*, const char* input, size_t length, double* output);
int Clear(PostfixCalc*);
int GetAnswer(PostfixCalc*, double* output);

#endif //POSTFIXCALC_H