/* Que 7: Write a program that creates a child process to execute a command. The command to be executed is passed on the command line.
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
 
int main(int argc, char *argv[]) {
    if(argc == 1) {
        printf("No Command Line Argument Passed with %s \n", argv[0]);
    }
    else {
        if(fork() == 0) execvp(argv[1], argv + 1);
    }
    return 0;
}
