/* Que 4: Write a program that creates a Zombie process. The program will show the process table entry to ensure that the child process becomes Zombie.
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
void sleepfunc(int n) {
    for(int i = 1; i <= n;i++) {
        sleep(1);
        printf("%d\t", i);
        fflush(stdout);
    }
}
 
int main() {
    if (fork() == 0){
        printf("Child : PID = %d \t PPID = %d \n\n", getpid(),  getppid());
        exit(0);
    }
    else {
        sleepfunc(10);
        printf("\n\nParent : PID = %d \t PPID = %d \n\n", getpid(),  getppid());
        system("ps -l");
        printf("\n");
    }
    return 0;
}
