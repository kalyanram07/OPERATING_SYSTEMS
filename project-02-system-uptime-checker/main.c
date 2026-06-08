#include <stdio.h>
#include <stdlib.h>
#include <sys/sysinfo.h> // Core OS Library: Contains the sysinfo system call and struct sysinfo

int main() {
    // Instantiate the sysinfo structural buffer in local stack memory
    struct sysinfo system_stats;

    printf("==================================================\n");
    printf("  Executing Project 2: System Uptime Checker       \n");
    printf("==================================================\n");

    /* Call the sysinfo system call. 
       It passes the memory address of our structure to the kernel.
       Returns 0 on success, -1 on failure.
    */
    if (sysinfo(&system_stats) != 0) {
        perror("Error: Failed to retrieve system statistics from kernel");
        return EXIT_FAILURE;
    }

    // The raw data from the kernel is stored inside system_stats.uptime (in seconds)
    long total_seconds = system_stats.uptime;

    // Time conversion algorithms
    long hours = total_seconds / 3600;
    long minutes = (total_seconds % 3600) / 60;
    long seconds = total_seconds % 60;

    // Print the raw metrics along with the formatted human-readable stream
    printf("Raw Kernel Uptime Counter : %ld seconds\n", total_seconds);
    printf("Formatted System Uptime   : %ld hours, %ld minutes, %ld seconds\n", hours, minutes, seconds);
    printf("==================================================\n");

    return EXIT_SUCCESS;
}
