#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    printf("====================================================\n");
    printf("       PROJECT 17: PROCESS EXECUTION TIMER          \n");
    printf("====================================================\n");

    struct timespec start_time, end_time;
    
    // Mark the baseline starting point using the Monotonic Hardware Clock
    if (clock_gettime(CLOCK_MONOTONIC, &start_time) == -1) {
        perror("Clock retrieval failed");
        exit(EXIT_FAILURE);
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } 
    else if (pid == 0) {
        // CHILD CONTEXT: Execute a simulation payload task
        printf("[CHILD] Executing compute-intensive task emulation...\n");
        
        // Simulating a minor execution payload via a spin loop
        volatile long long i;
        for (i = 0; i < 50000000LL; i++); 
        
        printf("[CHILD] Workload finished. Terminating context.\n");
        exit(0);
    } 
    else {
        // PARENT CONTEXT: Wait for the child to fully close out
        wait(NULL);
        
        // Immediately mark the absolute termination clock tick
        if (clock_gettime(CLOCK_MONOTONIC, &end_time) == -1) {
            perror("Clock retrieval failed");
            exit(EXIT_FAILURE);
        }

        // Calculate time differentials
        long seconds = end_time.tv_sec - start_time.tv_sec;
        long nanoseconds = end_time.tv_nsec - start_time.tv_nsec;
        
        // Handle mathematical underflows in nanosecond intervals
        if (nanoseconds < 0) {
            seconds--;
            nanoseconds += 1000000000L;
        }

        printf("\n[BENCHMARK REPORT]\n");
        printf(" -> Total Elapsed Seconds:      %ld s\n", seconds);
        printf(" -> Total Elapsed Nanoseconds:  %ld ns\n", nanoseconds);
        printf(" -> Precision Tracking Profile: Complete.\n\n");
    }

    return 0;
}
