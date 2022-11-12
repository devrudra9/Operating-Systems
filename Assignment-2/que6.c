/* Que 6: Write a program that creates a child process that will replace itself with the existing system code of “ls” let show.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
 
int main() {
    if(fork() == 0) execlp("ls", "ls", NULL);
    else wait(NULL);
    
    return 0;
}
