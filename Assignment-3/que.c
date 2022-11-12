/* Include the pthread library to do thread programming */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
 
void* check_ODDorEVEN(int* n) {
    int num = *n;
    if(num%2 == 0) printf("\n\tEVEN Number\n");
    else printf("\n\tODD Number\n");
}
 
void* check_ifPrime(int* n) {
    int num = *n;
    int flag = 1;
    for(int i = 2; i <= num/2; i++) {
        if(num%i == 0) {
            flag = 0;
            break;
        }
    }
    if(n == 1) flag = 0;
    if(!flag) printf("\n\tNot a Prime Number\n");
    else printf("\n\tPrime Number\n");
}
 
void* check_ifSquare(int* n) {
    int flag = 1;
    int l = 1, r = *n;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * mid == (*n)) flag = 0;
 
        if (mid * mid < (*n)) l = mid + 1;
        else r = mid - 1;
    }
    if(!flag) printf("\n\tPerfect Square\n");
    else printf("\n\tNot a Perfect Square\n");
}
 
int main(int argc, char *argv[]) {
    pthread_t thread1, thread2, thread3;
    int num;
    int* val1;
    int* val2;
    int* val3;
    printf("Enter the number : ");
    scanf("%d", &num);
 
    // QUESTION 1
    int que1 = pthread_create(&thread1, NULL, check_ODDorEVEN, &num);
    if(que1 != 0) printf(que1, "pthread_create");
    que1 = pthread_join(thread1, &val1);
    if(que1 != 0) printf(que1, "pthread_join");
 
    // QUESTION 2
    int que2 = pthread_create(&thread2, NULL, check_ifPrime, &num);
    if(que2 != 0) printf(que2, "pthread_create");
    que2 = pthread_join(thread2, &val2);
    if(que2 != 0) printf(que2, "pthread_join");
 
    // QUESTION 3
    int que3 = pthread_create(&thread3, NULL, check_ifSquare, &num);
    if(que3 != 0) printf(que3, "pthread_create");
    que3 = pthread_join(thread3, &val3);
    if(que3 != 0) printf(que3, "pthread_join");
    
    return 0;
}
