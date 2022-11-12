/* QUE 1 : Write a program showing that the parent and child process will not share the memory location, even global memory. */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
 
// GLOBAL VARIABLE
int x = 10;
 
int main() {
    pid_t forkRetn = fork();
 
    int y = 10;
    if(forkRetn == 0) {
        printf("This is CHILD\n");
        printf("Child process : x = %d\t y = %d\n", x + 2, y + 2); 
    } 
    else {
        printf("This is PARENT\n");
        printf("Parent process : x = %d\t y = %d\n", x - 2, y - 2); 
    }
    return 0;
}

/* So each process child and parent both have their own copy of global variable and local variable otherwise if they had shared it, 
we would have got Child Process Value local Variable = 10, global Variable = 20, 
in child process which was assigned in parent process which executed first but we didn’t. */
