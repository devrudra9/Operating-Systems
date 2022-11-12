/* QUE 2 : Write a program that creates a chain of n processes, where n is a command–line argument. */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    int i;
 
    if (argc == 1) {
        printf("No Command Line Argument Passed with %s \n", argv[0]);
        return 1;
    }
    int n = atoi(argv[1]);
    for(i = 0; i < n; i++) {
        if (fork() == 0) {
            printf("Child : PID = %d \t PPID = %d \n", getpid(), getppid());
        }
        else {
            printf("Parent : PID = %d \t PPID = %d \n", getpid(), getppid());
            break;
        }
    }
    return 0;
}
