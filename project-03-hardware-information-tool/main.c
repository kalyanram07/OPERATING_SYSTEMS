#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("==================================================\n");
    printf("  Executing Project 3: Hardware Information Tool  \n");
    printf("==================================================\n");

    FILE *cpu = fopen("/proc/cpuinfo", "r");
    FILE *mem = fopen("/proc/meminfo", "r");
    if (cpu == NULL || mem == NULL) {
        perror("Error opening hardware files");
        return 1;
    }

    char chunk[256];
    char cpu_model[128] = "Unknown Core Type";
    int cores = 0;

    while (fgets(chunk, sizeof(chunk), cpu)) {
        if (strncmp(chunk, "model name", 10) == 0) {
            char *match = strchr(chunk, ':');
            if (match) {
                strcpy(cpu_model, match + 2);
                cpu_model[strcspn(cpu_model, "\n")] = 0;
            }
        }
        if (strncmp(chunk, "processor", 9) == 0) {
            cores++;
        }
    }
    fclose(cpu);

    printf("--- CPU TELEMETRY ---\n");
    printf("Processor Model        : %s\n", cpu_model);
    printf("Active Processor Cores : %d\n\n", cores);

    long total_k = 0, avail_k = 0;
    while (fgets(chunk, sizeof(chunk), mem)) {
        if (strncmp(chunk, "MemTotal:", 9) == 0) sscanf(chunk, "MemTotal: %ld", &total_k);
        if (strncmp(chunk, "MemAvailable:", 13) == 0) sscanf(chunk, "MemAvailable: %ld", &avail_k);
    }
    fclose(mem);

    double t_gb = (double)total_k / (1024.0 * 1024.0);
    double a_gb = (double)avail_k / (1024.0 * 1024.0);
    double u_gb = t_gb - a_gb;
    double load = (t_gb > 0) ? ((u_gb / t_gb) * 100.0) : 0.0;

    printf("--- MEMORY TELEMETRY ---\n");
    printf("Total Installed RAM    : %.2f GB\n", t_gb);
    printf("Available/Free RAM     : %.2f GB\n", a_gb);
    printf("Memory Load Percentage : %.1f%%\n", load);
    printf("==================================================\n");

    return 0;
}
