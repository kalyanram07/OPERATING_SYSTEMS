#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <signal.h>
#include "system_shared.h"

void render_ui(SystemState *state) {
    printf("\033[H\033[J"); 
    printf("==============================================================\n");
    printf("      CAPSTONE OS DISTRIBUTED MONITOR & CONTROLLER UI        \n");
    printf("==============================================================\n");
    printf(" RAM TOTAL : %lu MB  |  RAM FREE : %lu MB  |  USAGE : %.2f%%\n",
           state->total_mem, state->free_mem, state->mem_usage_pct);
    printf(" TOTAL CPU CLOCK TICKS CAPTURED : %lu\n", state->total_cpu_time);
    printf("==============================================================\n\n");
    
    printf(" TRACKED PROCESSES IN MEMORY BUS:\n");
    printf("--------------------------------------------------------------\n");
    printf("   PID\t\t| COMMAND\t\t| ACCUMULATED WEIGHT\n");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < state->process_count; i++) {
        printf("   %d\t\t| %-15s\t| %.1f\n",
               state->processes[i].pid, state->processes[i].name, state->processes[i].cpu_usage);
    }
    printf("==============================================================\n");
    printf(" COMMAND CONSOLE ➔ [Format: <stop|resume|kill> <PID>]\n");
    printf(" Enter command (or 'exit'): ");
    fflush(stdout);
}

int main() {
    int shm_fd = shm_open(SHM_NAME, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("Dashboard open failure. Run worker daemon first!");
        return 1;
    }
    
    SystemState *shared_state = mmap(0, sizeof(SystemState), PROT_READ, MAP_SHARED, shm_fd, 0);
    sem_t *sem = sem_open(SEM_NAME, 0);

    fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    char input_buf[64];
    while (1) {
        sem_wait(sem);
        render_ui(shared_state);
        sem_post(sem);

        usleep(500000);

        int bytes_read = read(STDIN_FILENO, input_buf, sizeof(input_buf) - 1);
        if (bytes_read > 0) {
            input_buf[bytes_read - 1] = '\0'; 
            
            if (strcmp(input_buf, "exit") == 0) break;

            char action[16];
            int target_pid = 0;
            if (sscanf(input_buf, "%15s %d", action, &target_pid) == 2) {
                int sig_num = 0;
                if (strcmp(action, "stop") == 0) sig_num = SIGSTOP;
                else if (strcmp(action, "resume") == 0) sig_num = SIGCONT;
                else if (strcmp(action, "kill") == 0) sig_num = SIGKILL;

                if (sig_num != 0 && target_pid > 0) {
                    kill(target_pid, sig_num);
                }
            }
        }
    }

    sem_close(sem);
    printf("\nDashboard closed down smoothly.\n");
    return 0;
}