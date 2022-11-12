/* Que 8: Write a menu-driven program which will display every UNIX command and run on the user’s choice. */

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
 
int main(int argc, char *argv[]) {
    int cases;
    char *str;
    printf("1: whoami\t 2: hostname\t 3: pwd\t  4: ls\t  5: date\n");
 
    printf("\nEnter your choice : ");
    scanf("%d", &cases);
 
    switch(cases){
        case 1: 
            str = "whoami";
            break;
        case 2: 
            str = "hostname";
            break;
        case 3: 
            str = "pwd";
            break;
        case 4:
            str = "ls";
            break;
        case 5: 
            str = "date";
            break;
        default: 
            printf("*** Invalid case ***\n");
    }
    if(fork() == 0){
        execlp(str, str, NULL);
    } 
 
    return 0;
}
