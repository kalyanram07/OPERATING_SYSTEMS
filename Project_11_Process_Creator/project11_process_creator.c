#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("====================================================\n");
    printf("            PROJECT 11: PROCESS CREATOR             \n");
    printf("====================================================\n");
    printf("[Core Concept]: Preparing to clone Process Control Block (PCB)...\n");
    printf("Parent Process Pre-Fork Baseline PID: %d\n\n", getpid());

    // Trigger the kernel context cloning routine
    pid_t pid = fork();

    if (pid < 0) {
        // PCB cloning failed
        perror("Fork allocation failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // Execution path for the newly spawned Child
        printf("[CHILD PATH] Hello from the cloned child process!\n");
        printf("[CHILD PATH] My unique assigned PID is: %d\n", getpid());
        printf("[CHILD PATH] My creator's (Parent) PPID is: %d\n\n", getppid());
    } 
    else {
        // Execution path for the original Creator Parent
        printf("[PARENT PATH] Hello from the master creator process!\n");
        printf("[PARENT PATH] I spawned a child process with PID: %d\n", pid);
        printf("[PARENT PATH] My own ongoing PID remains: %d\n\n", getpid());
    }

    printf("[Exit State Check] Process Context ID %d is now terminating gracefully.\n", getpid());
    return 0;
}
