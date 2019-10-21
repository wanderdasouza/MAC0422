#include <lib.h>
#define batch	_batch
#include <unistd.h>
#include "mproc.h"


PUBLIC void do_batch(pid_t mp_pid)
{   
    message m;
    m.m1_i1 = mp_pid;
    _syscall(MM, 69, &m);
}
