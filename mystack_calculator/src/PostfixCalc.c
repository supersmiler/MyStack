#include "PostfixCalc.h"
#include "mystack.h"
#include <string.h>
#include <stdlib.h>
#include <math.h>

PostfixCalc* InitializePostfixCalc()
{
    PostfixCalc *this = (PostfixCalc *)malloc(sizeof(PostfixCalc));
    this->stackHandle = mystack_create(sizeof(double));
    this->answer = 0;

    return this;
}

void DestroyPostfixCalc(PostfixCalc** thisptr)
{
    if (thisptr == NULL)
    {
        return;
    }

    if (*thisptr == NULL)
    {
        return;
    }

    mystack_destroy((*thisptr)->stackHandle);

    free(*thisptr);
    *thisptr = NULL;
}

int Calculate(PostfixCalc* this, const char* input, size_t length, double* output)
{
    if (this == NULL)
    {
        return -1;
    }

    if (input == NULL)
    {
        return -1;
    }
    
    if (output == NULL)
    {
        return -1;
    }
    
    for (size_t i = 0; i < length; i++)
    {
        char eval = input[i];

        if (eval == '\0')
        {
            continue;
        }
        else if (eval == '+')
        {
            double left = 0;
            double right = 0;
            mystack_pop(this->stackHandle, &right);
            mystack_pop(this->stackHandle, &left);
            double result = left + right;
            mystack_push(this->stackHandle, &result);
        }
        else if(eval == '-')
        {
            double left = 0;
            double right = 0;
            mystack_pop(this->stackHandle, &right);
            mystack_pop(this->stackHandle, &left);
            double result = left - right;
            mystack_push(this->stackHandle, &result);
        }
        else if(eval == '*')
        {
            double left = 0;
            double right = 0;
            mystack_pop(this->stackHandle, &right);
            mystack_pop(this->stackHandle, &left);
            double result = left * right;
            mystack_push(this->stackHandle, &result);
        }
        else if(eval == '/')
        {
            double left = 0;
            double right = 0;
            mystack_pop(this->stackHandle, &right);
            mystack_pop(this->stackHandle, &left);
            double result = left / right;
            mystack_push(this->stackHandle, &result);
        }
        else if(eval == '^')
        {
            double left = 0;
            mystack_pop(this->stackHandle, &left);
            double result = pow(left, 2);
            mystack_push(this->stackHandle, &result);
        }
        else if(eval == 'v')
        {
            double left = 0;
            mystack_pop(this->stackHandle, &left);
            double result = sqrt(left);
            mystack_push(this->stackHandle, &result);
        }
        else
        {
            double num = (double)atoi(&eval);
            mystack_push(this->stackHandle, &num);
        }
    }

    mystack_pop(this->stackHandle, &this->answer);

    *output = this->answer;

    return 0;
}

int Clear(PostfixCalc* this)
{
    if (this == NULL)
    {
        return -1;        
    }
    
    this->answer = 0;
    return 0;
}

int GetAnswer(PostfixCalc* this, double* output)
{
    if (this == NULL)
    {
        return -1;        
    }

    if (output == NULL)
    {
        return -1;
    }
    
    
    *output = this->answer;

    return 0;
}

