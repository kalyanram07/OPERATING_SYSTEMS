#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void get_kernel_version() {
    FILE *fp = fopen("/proc/version", "r");
    if (!fp) {
        perror("Failed to open /proc/version");
        return;
    }
    char buffer[256];
    if (fgets(buffer, sizeof(buffer), fp)) {
        // Extract just the OS and kernel release text
        char *token = strtok(buffer, " ");
        printf("OS/Kernel: ");
        int count = 0;
        while (token && count < 3) {
            printf("%s ", token);
            token = strtok(NULL, " ");
            count++;
        }
        printf("\n");
    }
    fclose(fp);
}

void get_uptime() {
    FILE *fp = fopen("/proc/uptime", "r");
    if (!fp) {
        perror("Failed to open /proc/uptime");
        return;
    }
    double total_seconds;
    if (fscanf(fp, "%lf", &total_seconds) == 1) {
        int days = (int)total_seconds / 86400;
        int hours = ((int)total_seconds % 86400) / 3600;
        int minutes = ((int)total_seconds % 3600) / 60;
        
        printf("Uptime   : ");
        if (days > 0) printf("%dd ", days);
        printf("%dh %dm\n", hours, minutes);
    }
    fclose(fp);
}

void get_mem_info() {
    FILE *fp = fopen("/proc/meminfo", "r");
    if (!fp) {
        perror("Failed to open /proc/meminfo");
        return;
    }
    char label[50];
    long value;
    long mem_total = 0, mem_free = 0, mem_cached = 0, buffers = 0;

    while (fscanf(fp, "%s %ld kB", label, &value) != EOF) {
        if (strcmp(label, "MemTotal:") == 0) mem_total = value;
        else if (strcmp(label, "MemFree:") == 0) mem_free = value;
        else if (strcmp(label, "Buffers:") == 0) buffers = value;
        else if (strcmp(label, "Cached:") == 0) mem_cached = value;
    }
    fclose(fp);

    // In Linux, true "used" memory = Total - Free - Buffers - Cached
    long mem_used = mem_total - mem_free - buffers - mem_cached;

    printf("Memory   : %ld MB / %ld MB\n", mem_used / 1024, mem_total / 1024);
}

int main() {
    printf("--- SYSTEM INITIALIZATION INFOGRAPHIC ---\n");
    get_kernel_version();
    get_uptime();
    get_mem_info();
    printf("-----------------------------------------\n");
    return 0;
}
