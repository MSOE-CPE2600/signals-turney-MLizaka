/**
 * File: send_signal.c
 * Modified by: Andrew Lizak 
 * 
 * Brief summary of program:
 */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error enter pid along with gccing \n");
        return 1;
    }

    
    pid_t pid = atoi(argv[1]); // turns the string into an int 
    if (pid <= 0) {
        printf("error pid must be greater than 0 \n");
        return 1;
    }

    //rand numb gen 
    srand(time(NULL));
    int random_value = rand() % 100; // Generates a random integer between 0 and 99

    
    union sigval VAL;
    VAL.sival_int = random_value;

    // Send the signal
    if (sigqueue(pid, SIGUSR1, VAL) == -1) {
        perror("sigqueue");
        return 1;
    }

    printf("sent pid: %d value: %d\n", pid, random_value);

    return 0;
}