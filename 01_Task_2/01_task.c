#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "print_dan.h"

int globvar = 6;
static int globvar2 = 8;
char buf[] = "a write to stdout\n";
void err_sys(const char* x)
{
perror(x);
exit(1);
}

int main(void)
{
int var = 88;
pid_t pid;
globvar2 += 10;
if (write(STDOUT_FILENO, buf, sizeof(buf)-1) != sizeof(buf)-1)
err_sys("write error");
printf("before fork\n");
if ((pid = fork()) < 0) {
    err_sys("fork error");
    } else if (pid == 0) { /* child */
    globvar++;
    var++;
    } else {
    /* parent */
   sleep(2);
   }
 print_dan(var,pid);   
 printf("pid = %ld, glob = %d, glob2_m = %d, var = %d\n", (long)getpid(), globvar, globvar2, var);
 exit(0);
}