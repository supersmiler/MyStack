#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <unistd.h>

#include "mystack.h"

int main (int argc, char * argv[])
{
  printf("Hello world!\n");

  mystack_create(sizeof(int));

  return 0;
}
