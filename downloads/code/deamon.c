#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#ifndef HAVE_DAEMON

/* Daemonize myself. */
int daemon (int nochdir, int noclose)
{
    pid_t pid;

    pid = fork ();

    /* In case of fork is error. */
    if (pid < 0)
    {
        return -1;
    }

    /* In case of this is parent process. */
    if (pid != 0)
        exit (0);

    /* Become session leader and get pid. */
    pid = setsid();

    if (pid == -1)
    {
        return -1;
    }

    /* Change directory to root. */
    if (! nochdir)
        chdir ("/");

    /* File descriptor close. */
    if (! noclose)
    {
        int fd;
        fd = open ("/dev/null", O_RDWR, 0);
        if (fd != -1)
        {
            dup2 (fd, STDIN_FILENO);
            dup2 (fd, STDOUT_FILENO);
            dup2 (fd, STDERR_FILENO);
            if (fd > 2)
                close (fd);
        }
    }
    umask(0027);
    return 0;
}

int main()
{
    if (daemon(1, 1)) {
        fprintf(stderr, "daemon() failed!");
    }
    while(1);
    return 0;
}
#endif /* HAVE_DAEMON */
