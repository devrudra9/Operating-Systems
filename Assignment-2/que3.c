/* Que 3: Write a program that creates a tree of n processes where n is passed as a command-line argument. Then the original process should print the information after all children have exited.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main(int argc, char *argv[]) {
    int i;
    int n = atoi(argv[1]);
 
    if (argc == 1) {
        printf("No Command Line Argument Passed with %s \n", argv[0]);
        return 1;
    }
    for(i = 0; i < n; i++) {
        if(fork() == 0) {
            printf("Child : PID = %d \t PPID = %d \n", getpid(), getppid());
            exit(0);
        }
    }
 
    for(i = 0; i < n; i++) wait(NULL);
    printf("\nParent : PID = %d \t PPID = %d \n", getpid(), getppid());
    return 0;
}
