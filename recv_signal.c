/**
 * File: recv_signal.c
 * Modified by: Andrew Lizak 
 * 11/19/2024
 * LAB 10
 * Brief summary of program: SENDS a random number to specified pid 
 * reciving program must be able to interprate the pid 
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle(int sig, siginfo_t *info, void *context) {

    (void)context; 
    if (sig == SIGUSR1) {
        printf("sigusr1 with value: %d\n", info->si_value.sival_int);
    }
}

int main() {
    struct sigaction action;
    action.sa_sigaction = handle; 
    action.sa_flags = SA_SIGINFO;        
    sigemptyset(&action.sa_mask);        

    // Register SIGUSR1 handler
    if (sigaction(SIGUSR1, &action, NULL) == -1) {
        printf("ERROR WITH SIGACTION CALL\n");
        exit(1);
    }

    printf("SEND ME SIGUSR1 MY PID is: %d)\n", getpid());

    
    while (1) {
        pause(); 
    }

    return 0;
}