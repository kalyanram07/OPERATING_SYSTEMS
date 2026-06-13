#ifndef SYSTEM_SHARED_H
#define SYSTEM_SHARED_H

#include <sys/types.h>

#define SHM_NAME "/capstone_shm"
#define SEM_NAME "/capstone_sem"
#define MAX_PROCESSES 10

typedef struct {
    pid_t pid;
    char name[16];
    unsigned long utime;
    unsigned long stime;
    double cpu_usage;
} ProcessMetrics;

typedef struct {
    unsigned long total_mem;
    unsigned long free_mem;
    double mem_usage_pct;
    unsigned long total_cpu_time;
    int process_count;
    ProcessMetrics processes[MAX_PROCESSES];
} SystemState;

#endif