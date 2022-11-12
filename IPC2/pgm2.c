#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
 
int fds1[2];
int fds2[2];
char readmessage[20];
 
void sleepFunc(int n) {
    for(int i = 1; i <= n; i++) {
        printf("%d\t", i);
        sleep(1);
        fflush(stdout);
    }
}
 
void *threadFunc(void *start) {
    read(fds2[0], readmessage, sizeof(readmessage)); 
    printf("In thread : thread is reading : %s\n", readmessage);
    printf("\n");
    sleepFunc(3);
    printf("\n\n");
 
    char threadWriteMessage[20] = "Hello main !!";
    write(fds1[1], threadWriteMessage, sizeof(threadWriteMessage));
    printf("In Thread: thread is writing : %s\n", threadWriteMessage);
}
 
int main() {
    pthread_t thread_id;
    char mainWriteMessage[20] = "Hello thread !!";
 
    if(pipe(fds1) == -1 || pipe(fds2) == -1) {
        printf("Unable to create pipe \n");
        return 1;
    }
 
    write(fds2[1], mainWriteMessage, sizeof(mainWriteMessage));
    printf("\nIn main : main is writing : %s\n", mainWriteMessage);
 
    
    pthread_create(&thread_id, NULL, threadFunc, NULL);
    pthread_join(thread_id, NULL);
    read(fds1[0], readmessage, sizeof(readmessage)); 
    printf("In main : main is reading : %s\n\n", readmessage);
    
    return 0;
}
