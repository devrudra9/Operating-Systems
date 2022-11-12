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
