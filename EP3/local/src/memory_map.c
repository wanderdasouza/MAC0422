#define _MINIX 1
#define _POSIX_SOURCE 1

#include <stdio.h>
#include <pwd.h>
#include <curses.h>
#include <timers.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <termcap.h>
#include <termios.h>
#include <time.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#include <errno.h>

#include <sys/ioc_tty.h>
#include <sys/times.h>
#include <sys/types.h>
#include <sys/time.h>
#include <sys/select.h>

#include <minix/ipc.h>
#include <minix/config.h>
#include <minix/type.h>
#include <minix/const.h>

#include "/usr/src/servers/is/inc.h"

#include "/usr/src/servers/pm/mproc.h"
#include "/usr/src/kernel/const.h"
#include "/usr/src/kernel/proc.h"

/*Codigo adaptado do top.c, responsável por imprimir a memoria disponivel no sistema */
int print_memory(struct pm_mem_info *pmi)
{
        int h;
        int total_bytes = 0; 
        for(h = 0; h < _NR_HOLES; h++) {
                if(pmi->pmi_holes[h].h_base && pmi->pmi_holes[h].h_len) {
                        int bytes;
                        bytes = pmi->pmi_holes[h].h_len << CLICK_SHIFT;
                        total_bytes += bytes;
                }
        }

	printf("Memoria livre: %dK \n", total_bytes/1024);

	return 1;
}
void print_table(struct mproc mp[]){
    int i;
    struct mproc *mp_atual;
    for(i=0; i < NR_PROCS; i++){
        mp_atual = &mp[i];
        printf("pid: %d\t", mp_atual[i].mp_pid);
        printf("primeira posicao: %d\t", mp_atual[i].mp_seg[T].mem_phys);
        printf("ultima posicao: %d\n", mp_atual[i].mp_seg[S].mem_phys + mp_atual[i].mp_seg[S].mem_len);
    }
}
int main(int argc, char *argv[]){
    static struct pm_mem_info pmi;
    static struct mproc mp[NR_PROCS];
    getsysinfo(PM_PROC_NR, SI_PROC_TAB, mp);
    getsysinfo(PM_PROC_NR, SI_MEM_ALLOC, &pmi);
    print_table(mp);
    print_memory(&pmi);
}
