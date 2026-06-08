#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("==================================================\n");
    printf("  Executing Project 3: Hardware Information Tool  \n");
    printf("=================================================\n");
    FILE *f = fopen("/proc/cpuinfo", "r");
    FILE *m = fopen("/proc/meminfo", "r");
    if (f == NULL || m == NULL) {
        perror("Error opening system files");
        return 1;
    }
    char c[256];
    char cpu[128] = "Unknown";
    int cores = 0;

    while (fgets(c, 256, f)) {
        if (strncmp(c, "model name", 10) == 0) {
            char *k = strchr(c, ':');
            if (k && (cpu[0] == 'U' || cpu[0] == 'u')) {
                strcpy(cpu, k + 2);
                cpu[strcspn(cpu, "\n")] = 0;
            }
        }
        if (strncmp(c, "processor", 9) == 0) cores++;
    }
    fclose(f);

    printf("--- CPU TELEMETRY ---\n");
    printf("Processor Model        : %s\n", cpu);
    return 0;}
