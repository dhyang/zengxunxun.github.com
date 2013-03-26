#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>

static int keep_going = 1;

static void termination_handler(int signum) 
{
    fprintf(stderr,"SIGTERM received! exit!\n");
    keep_going = 0;
}

int main()
{
    struct sigaction act;
    act.sa_handler = termination_handler;
    sigemptyset(&act.sa_mask);
    sigaction(SIGTERM, &act, NULL);
    sigaction(SIGUSR1, &act, NULL);
    fprintf(stderr, "%d\n", getpid());
    while(keep_going);
    fprintf(stderr, "exit");    
    return 0;
}
