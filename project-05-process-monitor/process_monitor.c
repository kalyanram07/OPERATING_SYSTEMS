
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <ctype.h>
#include <string.h>

int is_pid_folder(const char *name) {
    for (int i = 0; name[i] != '\0'; i++) {
        if (!isdigit(name[i])) return 0;
    }
    return 1;
}

void list_processes() {
    DIR *dir = opendir("/proc");
    struct dirent *entry;

    if (!dir) {
        perror("Failed to open /proc directory");
        return;
    }

    printf("%-10s %-20s\n", "PID", "Process Name");
    printf("-----------------------------------\n");

    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type == DT_DIR && is_pid_folder(entry->d_name)) {
            char path[256]; 
            snprintf(path, sizeof(path), "/proc/%s/comm", entry->d_name);
            
            FILE *fp = fopen(path, "r");
            if (fp) {
                char proc_name[256]; 
                if (fgets(proc_name, sizeof(proc_name), fp)) {
                    proc_name[strcspn(proc_name, "\n")] = '\0';
                    printf("%-10s %-20s\n", entry->d_name, proc_name);
                }
                fclose(fp);
            }
        }
    }
    closedir(dir);
}

int main() {
    printf("=== CORE KERNEL ACTIVE PROCESS MONITOR ===\n");
    list_processes();
    return 0;
}

