/**
 * File: SIGNAL_SIGACTION.C
 * Modified by: ANdrew Lizak
 * 11/19/24
 * Brief summary of program:
 */

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handle(int sig, siginfo_t *info, void *context){
    (void)context;
    printf("Recived SIGUSR1 from process: %d\n", info->si_pid);
}

int main(){
    struct sigaction action;
    action.sa_sigaction = handle;
    action.sa_flags = SA_SIGINFO;
    sigemptyset(&action.sa_mask);

    sigaction(SIGUSR1, &action, NULL);
    printf("send me SIGUSR1 my pid: %d\n", getpid());
    while(1){
        pause();
    }
return 0;
}