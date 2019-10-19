/* The kernel call implemented in this file:
 *   m_type:	SYS_BATCH
 *
 * The parameters for this kernel call are:
 *    m1_i1:	PR_ENDPT  		(process that did exec call)
 *    m1_p1:	PR_STACK_PTR		(new stack pointer)
 *    m1_p2:	PR_NAME_PTR		(pointer to program name)
 *    m1_p3:	PR_IP_PTR		(new instruction pointer)
 */
#include "../system.h"
#include <string.h>
#include <signal.h>
#include <minix/endpoint.h>

/* ######################################################## */
PUBLIC int do_batch(m_ptr)
register message *m_ptr;	/* pointer to request message */
{
  /* IMPLEMENTAR ESSA CARALHA */  
  return(OK);
}
/* ######################################################## */
