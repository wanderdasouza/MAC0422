#include "syslib.h"

PUBLIC int sys_callbatch(int *rp)
int proc;			/* process that did exec */
char *ptr;			/* new stack pointer */
char *prog_name;		/* name of the new program */
vir_bytes initpc;
{
/* A process has exec'd.  Tell the kernel. */

  message m;

  m.PR_ENDPT = proc;
  m.PR_STACK_PTR = ptr;
  m.PR_NAME_PTR = prog_name;
  m.PR_IP_PTR = (char *)initpc;
  return(_taskcall(SYSTASK, SYS_EXEC, &m));
}

/*
PUBLIC int sys_mycall (some parameter)
{
   int r; // the return variable.
   message m; // create a message for the call.
   m.foo = bar;
   /**
    * The system library invokes a kernel call by
    * sending a message to the kernel with _taskcall().
    
   r = _taskcall(SYSTASK, SYS_MYCALL, &m );
   return r;
}
*/
