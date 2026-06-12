#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

// Structure to capture a process sample
typedef struct {
    char pid[16];
    char name[256];
    unsigned long long total_ticks;
} ProcessSample;

// Function to check if a directory is a valid PID
int is_pid_folder(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isdigit(name[i])) return 0;
    }
    return 1;
}

// Function to read global total CPU ticks from /proc/stat
unsigned long long get_global_cpu_ticks() {
    FILE *fp = fopen("/proc/stat", "r");
    if (!fp) return 0;

    char cpu_label[16];
    unsigned long long user, nice, system, idle, iowait, irq, softirq;
    if (fscanf(fp, "%s %llu %llu %llu %llu %llu %llu %llu", 
               cpu_label, &user, &nice, &system, &idle, &iowait, &irq, &softirq) >= 8) {
        fclose(fp);
        return user + nice + system + idle + iowait + irq + softirq;
    }
    fclose(fp);
    return 0;
}

// Function to read total ticks for a specific PID
unsigned long long get_process_ticks(const char *pid, char *name_buf, size_t buf_size) {
    char path[512];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    FILE *fp = fopen(path, "r");
    if (!fp) return 0;

    unsigned long long utime = 0, stime = 0;
    long long cutime = 0, cstime = 0;
    char comm[256];
    strcpy(comm, "Unknown");

    if (fscanf(fp, "%*d (%[^)]) %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %llu %llu %lld %lld",
               comm, &utime, &stime, &cutime, &cstime) >= 1) {
        if (name_buf) {
            strncpy(name_buf, comm, buf_size - 1);
            name_buf[buf_size - 1] = '\0';
        }
        fclose(fp);
        return utime + stime + cutime + cstime;
    }
    fclose(fp);
    return 0;
}

int main() {
    ProcessSample old_samples[1024];
    char current_name[256];

    while (1) {
        int old_count = 0;
        unsigned long long global_ticks_1 = get_global_cpu_ticks();

        DIR *dir = opendir("/proc");
        struct dirent *entry;
        if (!dir) {
            perror("Failed to open /proc");
            return 1;
        }

        while ((entry = readdir(dir)) != NULL && old_count < 1024) {
            if (entry->d_type == DT_DIR && is_pid_folder(entry->d_name)) {
                strncpy(old_samples[old_count].pid, entry->d_name, sizeof(old_samples[old_count].pid) - 1);
                old_samples[old_count].pid[sizeof(old_samples[old_count].pid) - 1] = '\0';
                
                old_samples[old_count].total_ticks = get_process_ticks(
                    entry->d_name, old_samples[old_count].name, sizeof(old_samples[old_count].name)
                );
                old_count++;
            }
        }
        closedir(dir);

        usleep(100000);

        unsigned long long global_ticks_2 = get_global_cpu_ticks();
        unsigned long long global_delta = global_ticks_2 - global_ticks_1;

        printf("\033[H\033[J");
        printf("=======================================================================\n");
        printf("       LIVE KERNEL PROCESS ACTIVITY DASHBOARD (Mini-htop)              \n");
        printf("=======================================================================\n");
        printf("%-8s %-25s %-15s\n", "PID", "Process Name", "Live CPU %%");
        printf("-----------------------------------------------------------------------\n");

        for (int i = 0; i < old_count; i++) {
            unsigned long long ticks_2 = get_process_ticks(old_samples[i].pid, current_name, sizeof(current_name));
            
            if (ticks_2 > 0 && global_delta > 0) {
                unsigned long long proc_delta = ticks_2 - old_samples[i].total_ticks;
                double cpu_percent = ((double)proc_delta / global_delta) * 100.0;

                if (cpu_percent >= 0.0) {
                    printf("%-8s %-25s %-15.2f%%\n", old_samples[i].pid, old_samples[i].name, cpu_percent);
                }
            }
        }
        printf("-----------------------------------------------------------------------\n");
        printf("[Press Ctrl + C to exit live metrics engine loop]\n");
    }
    return 0;
}
