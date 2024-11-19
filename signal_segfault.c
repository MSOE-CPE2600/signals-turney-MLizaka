/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by:
 * 
 * Brief summary of modifications:
 */


#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handle_sig(int sig){
    printf("the seg fault was recived now returning from the program gracefully\n");
    exit(1);
}

int main (int argc, char* argv[]) {
    // Declare a null pointer
    int* i = NULL;
    signal(SIGSEGV, handle_sig);

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}