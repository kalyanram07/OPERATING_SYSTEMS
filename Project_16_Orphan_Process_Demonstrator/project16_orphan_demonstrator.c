#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("====================================================\n");
    printf("       PROJECT 16: ORPHAN PROCESS DEMONSTRATOR      \n");
    printf("====================================================\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // CHILD CONTEXT: Sleep while parent exits early
        printf("[CHILD] Initial State -> My PID: %d, My Parent's PPID: %d\n", getpid(), getppid());
        printf("[CHILD] Going to sleep for 5 seconds while my parent exits early...\n\n");
        
        sleep(5);
        
        // Waking up after parent is dead to check new adoption status
        printf("[CHILD] Waking Up State -> My PID: %d, My NEW Adopted PPID: %d\n", getpid(), getppid());
        printf("[CHILD] Notice that my PPID has changed to 1 (systemd) or a local system sub-reaper container!\n");
        exit(0);
    } 
    else {
        // PARENT CONTEXT: Exit immediately
        printf("[PARENT] My PID is %d. I am exiting right now...\n", getpid());
        exit(0);
    }

    return 0;
}
