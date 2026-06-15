#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("====================================================\n");
    printf("       PROJECT 13: PROCESS TREE VISUALIZER          \n");
    printf("====================================================\n");
    
    pid_t root_pid = getpid();
    printf("[ROOT PARENT] Main Node Initialized. PID: %d\n\n", root_pid);

    pid_t child_a = fork();

    if (child_a < 0) {
        perror("Fork A failed");
        exit(EXIT_FAILURE);
    } 
    else if (child_a == 0) {
        printf(" ├── [CHILD A] Spawning... PID: %d, PPID: %d\n", getpid(), getppid());
        
        pid_t grandchild = fork();
        if (grandchild < 0) {
            perror("Grandchild fork failed");
            exit(EXIT_FAILURE);
        }
        else if (grandchild == 0) {
            printf(" │    └── [GRANDCHILD A1] Spawning... PID: %d, PPID: %d\n", getpid(), getppid());
            sleep(1);
            printf(" │    └── [GRANDCHILD A1] Terminating.\n");
            exit(0);
        }
        
        wait(NULL);
        printf(" ├── [CHILD A] Terminating.\n");
        exit(0);
    }

    sleep(1); 
    pid_t child_b = fork();

    if (child_b < 0) {
        perror("Fork B failed");
        exit(EXIT_FAILURE);
    }
    else if (child_b == 0) {
        printf(" ├── [CHILD B] Spawning... PID: %d, PPID: %d\n", getpid(), getppid());
        sleep(1);
        printf(" ├── [CHILD B] Terminating.\n");
        exit(0);
    }

    wait(NULL);
    wait(NULL);
    printf("\n[ROOT PARENT] All children reaped. Tree execution finished safely.\n");
    return 0;
}
