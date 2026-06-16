#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("====================================================\n");
    printf("       PROJECT 15: ZOMBIE PROCESS DEMONSTRATOR      \n");
    printf("====================================================\n");

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // CHILD CONTEXT: Exit immediately
        printf("[CHILD] My PID is %d. I am exiting right now to become a zombie...\n", getpid());
        exit(0);
    } 
    else {
        // PARENT CONTEXT: Sleep without calling wait()
        printf("[PARENT] I spawned a child with PID: %d\n", pid);
        printf("[PARENT] I am going to sleep for 15 seconds WITHOUT calling wait().\n");
        printf("[PARENT] RUN THIS COMMAND IN A SEPARATE WSL TERMINAL TO SEE THE ZOMBIE:\n");
        printf("         ps -ef | grep defunct\n\n");
        
        sleep(15);
        
        printf("[PARENT] Waking up and terminating. The operating system will now clean up the zombie.\n");
    }

    return 0;
}
