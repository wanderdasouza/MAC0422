#include <lib.h>
#include <unistd.h>

PUBLIC int memalloc(int mode)
{
  message m;
  m.m1_i1 = mode;
  return(_syscall(MM, MEMALLOC, &m));
}
