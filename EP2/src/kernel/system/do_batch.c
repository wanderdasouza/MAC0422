/* ######################################################## */
/* The kernel call implemented in this file:
 *   m_type:	SYS_BATCH
 *
 * The parameters for this kernel call are:
 *  m1_i1: indice do processo na tabela de processos
 *   
 */
#include "../system.h"
#include <string.h>
#include <signal.h>
#include "mproc.h"
#include <minix/endpoint.h>

/*===========================================================================*
 *				do_batch					     *
 *===========================================================================*/

/* m1_i1: indice do processo a ser enfileirado na tabela de processos */
PUBLIC void do_batch(m_ptr)
register message *m_ptr;	/* pointer to request message */
{
    register struct proc *rp;
    int indice;
    int numero_batch;

    numero_batch = 15; /* indice da fila BATCH */

    indice = m_ptr->m1_i1; /* resgata indice */

    rp = proc_addr(indice); /* pega ponteiro do processo do indice */

    /* add to tail of queue */
    rdy_tail[numero_batch]->p_nextready = rp;		/* chain tail of queue */	
    rdy_tail[numero_batch] = rp;				/* set new queue tail */
    rp->p_nextready = NIL_PROC;		/* mark new end */
}

/* ######################################################## */