#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int *p;
  memalloc(1);
  p = malloc(4*sizeof(int));
  return 0;
}