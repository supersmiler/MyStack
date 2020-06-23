#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "ReverseList.h"
#include "Calculator.h"

int main(int argc, char *argv[])
{
  int selected;

  while (true)
  {
    printf("\n"
           "Select a assignment\n"
           "===================\n"
           "[1] Reverse list\n"
           "[2] Calculator\n");

    printf("Enter number :");
    scanf("%d", &selected);

    switch (selected)
    {
    case 1:
      reverseList();
      break;
    case 2:
      calculator();
      break;
    default:
      printf("Invalid selection!\n");
      break;
    }
  }

  return 0;
}


