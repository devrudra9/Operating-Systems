/* Que 5: Write a C program where the parent must wait for the child to die and then show the exit status of the child process.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main() {
    int status;
 
    if(fork() == 0) {
        printf("Child : PID = %d \t PPID = %d \n\n", getpid(), getppid());
    }
    else {
        wait(&status);
        printf("Parent : PID = %d \t PPID = %d \n\n", getpid(), getppid());
        printf("Child STATUS = %d \n\n", WIFSIGNALED(status));
        system("ps -l");
        printf("\n");
    }
    return 0;
}
