#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

void print_process_header() {
    printf("==================================================\n");
    printf("  Executing Project 4: Real-Time Process Monitor  \n");
    printf("==================================================\n");
    printf("%-8s %-20s %-8s\n", "PID", "PROCESS NAME", "STATE");
    printf("--------------------------------------------------\n");
}

int main() {
    print_process_header();
    DIR *dir = opendir("/proc");
    if (dir == NULL) {
        perror("Error opening /proc directory");
        return 1;
    }
    struct dirent *entry;
    char path[512];
    char line[256];
    int count = 0;
    while ((entry = readdir(dir)) != NULL && count < 15) {
        if (!isdigit(entry->d_name[0])) continue;
        snprintf(path, sizeof(path), "/proc/%s/stat", entry->d_name);
        FILE *f = fopen(path, "r");
        if (f) {
            if (fgets(line, sizeof(line), f)) {
                int pid;
                char comm[256];
                char state;
                sscanf(line, "%d (%255[^)]) %c", &pid, comm, &state);
                printf("%-8d %-20s %-8c\n", pid, comm, state);
                count++;
            }
            fclose(f);
        }
    }
    closedir(dir);
    printf("==================================================\n");
    return 0;
}
