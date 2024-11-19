/**
 * File: signal_alarm.c
 * Modified by: Andrew lizak
 * 
 * Brief summary of program:
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void handle_sig(int sig);

int main(){
    signal(SIGALRM, handle_sig);
    printf("race to send an alarm siganl before the int overflows\n");
    printf("ALARM IN 5! \n");
    alarm(5);
    int a = 5;
    int b = 5;
    while(1){
        a = a * b;
        printf("%d \n", a);
        sleep(1);
    }
    return 0;
}

void handle_sig(int sig){
    printf("THE ALARM WAS RECIVED ENDING RAPID COMPUTATION OF MATH \n");
    exit(1);
}