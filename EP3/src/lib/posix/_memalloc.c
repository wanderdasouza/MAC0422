#include <lib.h>
#include <unistd.h>

PUBLIC int memalloc(int mode)
{
  message m;
  m.m1_i1 = mode;
  m.m2_i2 = geteuid();
  return(_syscall(MM, 69, &m));
}
