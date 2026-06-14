#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("====================================================\n");
    printf("        PROJECT 12: PARENT-CHILD DEMO               \n");
    printf("====================================================\n");

    int test_counter = 100;
    printf("[Initial State] Shared variable baseline value: %d\n\n", test_counter);

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        printf("[CHILD] Executing... My PID: %d\n", getpid());
        printf("[CHILD] Original counter value seen by child: %d\n", test_counter);
        test_counter = test_counter + 50;
        printf("[CHILD] Modified counter value inside child memory: %d\n\n", test_counter);
    } 
    else {
        sleep(1); 
        printf("[PARENT] Executing... My PID: %d\n", getpid());
        printf("[PARENT] Counter value inside parent memory: %d\n", test_counter);
        printf("[PARENT] Notice that the child modifications DID NOT affect me.\n\n");
    }

    return 0;
}
