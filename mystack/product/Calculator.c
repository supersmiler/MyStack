#include "Calculator.h"

void calculator()
{
    int handle = mystack_create(sizeof(double));
    char input[100];
    printf("Enter a sum without spaces:");
    scanf("%s", input);
    if(strlen(input) < 2)
    {
        printf("Incorrect input!");
        return;
    }
    double length = strlen(input); 

    for (size_t i = 0; i < length; i++)
    {
        char inputChar = input[i];
        switch(inputChar)
        {
            case '\0':
                break;
            case ' ':
                break;
            case '^':
            {
                double number = 0;
                mystack_pop(handle, &number);
                double result = number * number;
                mystack_push(handle, &result);
                break;
            }
            case '-':
            { 
                double firstNumber = 0;
                double secondNumber = 0;
                mystack_pop(handle, &secondNumber);
                mystack_pop(handle, &firstNumber);
                double result = firstNumber - secondNumber;
                mystack_push(handle, &result);
                break;
            }
            case '*':
            {
                double firstNumber = 0;
                double secondNumber = 0;
                mystack_pop(handle, &secondNumber);
                mystack_pop(handle, &firstNumber);
                double result = firstNumber * secondNumber;
                mystack_push(handle, &result);
                break;
            }
            case '+':
            {
                double firstNumber = 0;
                double secondNumber = 0;
                mystack_pop(handle, &secondNumber);
                mystack_pop(handle, &firstNumber);
                double result = firstNumber + secondNumber;
                mystack_push(handle, &result);
                break;
            }
            case '/':
            {
                double firstNumber = 0;
                double secondNumber = 0;
                mystack_pop(handle, &secondNumber);
                mystack_pop(handle, &firstNumber);
                double result = firstNumber / secondNumber;
                mystack_push(handle, &result);
                break;
            }
            default:
            {
                double number = (double)atoi(&inputChar);
                mystack_push(handle, &number);
                break;
            }
        }
    }

    double answer = 0;

    mystack_pop(handle, &answer);

    printf("Answer: %f\n", answer);
    mystack_destroy(handle);
}