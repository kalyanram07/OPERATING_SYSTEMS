#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <ctype.h>

// Function to check if a directory name is a valid PID
int is_pid_folder(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isdigit(name[i])) return 0;
    }
    return 1;
}

// Function to extract physical memory usage (VmRSS) from /proc/[PID]/status
long get_process_memory(const char *pid) {
    char path[256];
    char line[256];
    long rss_memory = 0;

    snprintf(path, sizeof(path), "/proc/%s/status", pid);
    FILE *fp = fopen(path, "r");
    if (!fp) return 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, "VmRSS:", 6) == 0) {
            sscanf(line, "VmRSS: %ld", &rss_memory);
            break;
        }
    }
    fclose(fp);
    return rss_memory;
}

// Function to print resource metrics for a single target process
void monitor_process(const char *pid) {
    char stat_path[256];
    char comm_path[256];
    char proc_name[256];
    
    strcpy(proc_name, "Unknown");
    
    // Read Process Name safely
    snprintf(comm_path, sizeof(comm_path), "/proc/%s/comm", pid);
    FILE *fp_comm = fopen(comm_path, "r");
    if (fp_comm) {
        if (fgets(proc_name, sizeof(proc_name), fp_comm)) {
            proc_name[strcspn(proc_name, "\n")] = '\0';
        }
        fclose(fp_comm);
    } else {
        return; 
    }

    // Read CPU Ticks from /proc/[PID]/stat
    snprintf(stat_path, sizeof(stat_path), "/proc/%s/stat", pid);
    FILE *fp_stat = fopen(stat_path, "r");
    if (!fp_stat) return;

    unsigned long utime, stime;
    long cutime, cstime;
    
    if (fscanf(fp_stat, "%*d %*s %*c %*d %*d %*d %*d %*d %*u %*u %*u %*u %*u %lu %lu %ld %ld",
               &utime, &stime, &cutime, &cstime) == 4) {
        
        long total_ticks = utime + stime + cutime + cstime;
        long memory_kb = get_process_memory(pid);

        printf("%-7s %-22s %-15ld %-15ld KB\n", pid, proc_name, total_ticks, memory_kb);
    }
    fclose(fp_stat);
}

int main() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open /proc system track");
        return 1;
    }

    printf("\n=== REAL-TIME PROCESS RESOURCE METRICS AUDITOR ===\n");
    printf("%-7s %-22s %-15s %-15s\n", "PID", "Process Name", "Total CPU Ticks", "Physical RAM");
    printf("-----------------------------------------------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && is_pid_folder(entry->d_name)) {
            monitor_process(entry->d_name);
        }
    }

    closedir(dir);
    printf("-----------------------------------------------------------------------\n");
    return 0;
}
