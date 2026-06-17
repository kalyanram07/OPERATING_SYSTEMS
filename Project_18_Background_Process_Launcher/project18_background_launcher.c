#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("====================================================\n");
    printf("       PROJECT 18: BACKGROUND PROCESS LAUNCHER       \n");
    printf("====================================================\n");
    printf("[Interface]: Initializing background launch sequence...\n\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("Background fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // CHILD CONTEXT: Run a long task detached in the background
        printf("[BACKGROUND TASK] Child spawned silently. PID: %d\n", getpid());
        printf("[BACKGROUND TASK] Simulating heavy background workload operations...\n");
        
        // Sleep for 4 seconds to mimic a deep database backup or system sync
        sleep(4); 
        
        printf("\n\n[BACKGROUND TASK] PID %d has finished its work completely in the background.\n", getpid());
        exit(0);
    } 
    else {
        // PARENT CONTEXT: Non-blocking immediate return
        printf("[LAUNCH SUCCESS] Parent process tracking ID: %d\n", getpid());
        printf("[LAUNCH SUCCESS] Child process with PID %d shifted to the background.\n", pid);
        printf("[INTERFACE]: Handing control back immediately. You can keep typing!\n\n");
        
        // The parent exits or returns control without calling wait()
        // We will loop a basic prompt to show you that the parent isn't frozen!
        int count = 3;
        while (count > 0) {
            printf("[Main Interface Shell]: Active and awaiting user entry (%d)...\n", count);
            sleep(1);
            count--;
        }
    }

    printf("[Interface]: Main shell launcher routine exiting gracefully.\n");
    return 0;
}
