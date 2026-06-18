#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
    printf("====================================================\n");
    printf("       PROJECT 20: CPU USAGE BY PROCESS             \n");
    printf("====================================================\n");
    printf("[Core Engine]: Accessing internal kernel runtime metrics...\n\n");

    volatile double d = 0.0;
    for (long i = 0; i < 30000000L; i++) {
        d += (double)i * 1.5;
    }

    FILE *fp = fopen("/proc/self/stat", "r");
    if (fp == NULL) {
        perror("Failed to query /proc/self/stat");
        exit(EXIT_FAILURE);
    }

    // Allocate memory dynamically as a raw pointer to bypass bracket parsing issues
    char *cpu_buffer = (char *)malloc(2048);
    if (cpu_buffer == NULL) {
        perror("Memory allocation failed");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    
    // Initialize the memory
    char *ptr = cpu_buffer;
    for (int i = 0; i < 2048; i++) {
        ptr[i] = 0;
    }

    if (fgets(cpu_buffer, 2048, fp) == NULL) {
        perror("Failed to read statistical stream");
        free(cpu_buffer);
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fclose(fp);

    char *token = strtok(cpu_buffer, " ");
    int field_index = 1;
    
    unsigned long utime = 0;
    unsigned long stime = 0;

    while (token != NULL) {
        if (field_index == 14) {
            utime = strtoul(token, NULL, 10);
        } else if (field_index == 15) {
            stime = strtoul(token, NULL, 10);
            break; 
        }
        token = strtok(NULL, " ");
        field_index++;
    }

    printf("[KERNEL METRICS REPORT]\n");
    printf(" -> User Space CPU Ticks (utime):   %lu jiffies\n", utime);
    printf(" -> Kernel Space CPU Ticks (stime): %lu jiffies\n", stime);
    printf(" -> Total Combined Compute Lifespan: %lu jiffies\n\n", (utime + stime));
    printf("[Assessment]: Jiffies extraction compiled and parsed successfully.\n");
    printf("====================================================\n");

    free(cpu_buffer);
    return 0;
}
