#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    printf("====================================================\n");
    printf("       PROJECT 19: PROCESS PRIORITY VIEWER          \n");
    printf("====================================================\n");

    // Extract niceness of the current process
    // PRIO_PROCESS means we are querying by PID. A PID of 0 evaluates to "self".
    int self_nice = getpriority(PRIO_PROCESS, 0);
    
    // Extract niceness of the creator parent process
    int parent_nice = getpriority(PRIO_PROCESS, getppid());

    printf("[SCHEDULER STATUS]\n");
    printf(" -> Current Process PID: %d | Nice Level: %d\n", getpid(), self_nice);
    printf(" -> Parent Process PPID: %d | Nice Level: %d\n\n", getppid(), parent_nice);

    printf("[Priority Assessment]:\n");
    if (self_nice == 0) {
        printf(" -> Running with regular, standard base scheduling weights.\n");
    } else if (self_nice < 0) {
        printf(" -> Running with high-priority administrative privileges.\n");
    } else {
        printf(" -> Running with low-priority background/nice adjustments.\n");
    }
    printf("\n====================================================\n");

    return 0;
}
