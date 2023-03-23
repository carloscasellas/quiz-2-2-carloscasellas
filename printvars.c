#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
char *custom_env[] = {"USER=Pikachu", "PATH=/tmp", NULL};

int main(void)
{
    
    int waitid;

    pid_t pid = fork();

    if(pid != 0) {

        printf("Running parent process PID: %d\n\n", getpid());

    } else {

        printf("Running child process PID: %d\n", getpid());
        execle((char*) "echoall", (char*) "echoall" , (char*) "Bandicoot", (char*) "Pacman", NULL, custom_env);
        exit(0);

    }

    waitpid(pid, &waitid, 0);

    pid_t otherPid = fork();
    if(otherPid == 0) {

        printf("Running child process PID: %d\n", getpid());
        execlp((char*) "echoall", (char*) "echoall" , (char*) "Spyro", NULL);
        exit(0);

    }

    waitpid(otherPid, &waitid, 0);

    exit(0);

}