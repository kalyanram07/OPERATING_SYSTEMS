#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>
#include <dirent.h>
#include <ctype.h>
#include "system_shared.h"

void get_system_metrics(SystemState *state) {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (fp) {
        char label[32];
        unsigned long value;
        unsigned long total = 0, free = 0;
        while (fscanf(fp, "%31s %lu kB", label, &value) != EOF) {
            if (strcmp(label, "MemTotal:") == 0) total = value;
            if (strcmp(label, "MemFree:") == 0) free = value;
        }
        fclose(fp);
        state->total_mem = total / 1024;
        state->free_mem = free / 1024;
        state->mem_usage_pct = total > 0 ? ((double)(total - free) / total) * 100.0 : 0.0;
    }

    fp = fopen("/proc/stat", "r");
    if (fp) {
        char cpu[8];
        unsigned long user, nice, system, idle;
        if (fscanf(fp, "%7s %lu %lu %lu %lu", cpu, &user, &nice, &system, &idle) != EOF) {
            state->total_cpu_time = user + nice + system + idle;
        }
        fclose(fp);
    }
}

void get_process_metrics(SystemState *state) {
    DIR *dir = opendir("/proc");
    if (!dir) return;
    struct dirent *entry;
    int count = 0;

    while ((entry = readdir(dir)) != NULL && count < MAX_PROCESSES) {
        if (!isdigit(entry->d_name)) continue;
        
        char path[64];
        snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
        FILE *fp = fopen(path, "r");
        if (fp) {
            ProcessMetrics *proc = &state->processes[count];
            unsigned long utime, stime;
            char comm[256];
            
            if (fscanf(fp, "%d (%255[^)]) %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %lu %lu",
                       &proc->pid, comm, &utime, &stime) >= 4) {
                strncpy(proc->name, comm, 15);
                proc->name[15] = '\0';
                proc->utime = utime;
                proc->stime = stime;
                proc->cpu_usage = (double)(utime + stime) * 0.1;
                count++;
            }
            fclose(fp);
        }
    }
    state->process_count = count;
    closedir(dir);
}

int main() {
    int shm_fd = shm_open(SHM_NAME, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, sizeof(SystemState));
    SystemState *shared_state = mmap(0, sizeof(SystemState), PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sem_t *sem = sem_open(SEM_NAME, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("Worker semaphore open failed");
        return 1;
    }

    printf("[Worker Daemon]: Ingestion loop initialized. Gathering background metrics...\n");

    SystemState local_state;
    while (1) {
        memset(&local_state, 0, sizeof(SystemState));
        get_system_metrics(&local_state);
        get_process_metrics(&local_state);

        sem_wait(sem);
        memcpy(shared_state, &local_state, sizeof(SystemState));
        sem_post(sem);

        usleep(500000);
    }

    sem_close(sem);
    return 0;
}