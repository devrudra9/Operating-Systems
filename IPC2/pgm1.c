#include<stdio.h>
#include<unistd.h>
#include <string.h>
#include <sys/wait.h>
 
// NOTE : Double Timer in output is showed to show that both are running at the same time but is not clear which one of Parent or Child will be executed first.
 
void sleepFunc(int n) {
    for(int i = 1; i <= n; i++) {
        printf("%d\t", i);
        sleep(1);
        fflush(stdout);
    }
}
 
int main() {
    int fds1[2], fds2[2];
    char parentWriteMessage[20] = "Hello Child !!";
    char childWriteMessage[20] = "Hello Parent !!";
    char readmessage[20];
 
    if (pipe(fds1) == -1 || pipe(fds2) == -1) {
        printf("Unable to create pipe \n");
        return 1;
    }
 
    // PARENT PROCESS
    if (fork() != 0) { 
        close(fds1[0]); 
        close(fds2[1]);
        printf("\n");
        printf("In Parent: Parent is writing : %s\n", parentWriteMessage);
        write(fds1[1], parentWriteMessage, sizeof(parentWriteMessage));
 
        sleepFunc(3);
 
        read(fds2[0], readmessage, sizeof(readmessage));
        printf("In Parent: Parent is reading : %s\n\n", readmessage);
    } 
 
    // CHILD PROCESS
    else { 
        close(fds1[1]);
        close(fds2[0]);
        read(fds1[0], readmessage, sizeof(readmessage));
        printf("In Child: Child is reading : %s\n\n", readmessage);
        
        sleepFunc(3);
 
        printf("\n\nIn Child: Child is writing : %s\n", childWriteMessage);
        write(fds2[1], childWriteMessage, sizeof(childWriteMessage));
    }
    return 0;
}
