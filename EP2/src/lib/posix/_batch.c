#include <lib.h>
#include <unistd.h>


PUBLIC void batch(pid_t mp_pid)
{   
    message m;
    m.m1_i1 = mp_pid;
    _syscall(MM, BATCH, &m);
}
