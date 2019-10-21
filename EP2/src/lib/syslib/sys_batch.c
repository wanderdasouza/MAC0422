/* ######################################################## */
#include "syslib.h"

PUBLIC int sys_batch(pid_t pid)
{

  message m;

  m.m1_i1 = pid;
  return(_taskcall(SYSTASK, SYS_BATCH, &m));
}
/* ######################################################## */