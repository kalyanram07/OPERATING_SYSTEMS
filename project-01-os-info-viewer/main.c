#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>

int main() {
    struct utsname system_buffer;

    printf("==================================================\n");
    printf("  Executing Project 1: OS Information Viewer       \n");
    printf("==================================================\n");

    if (uname(&system_buffer) != 0) {
        perror("Error: Failed to fetch system info from kernel");
        return EXIT_FAILURE;
    }

    printf("Operating System Name : %s\n", system_buffer.sysname);
    printf("Network Hostname      : %s\n", system_buffer.nodename);
    printf("OS Release Version    : %s\n", system_buffer.release);
    printf("OS Build Version      : %s\n", system_buffer.version);
    printf("Hardware Architecture : %s\n", system_buffer.machine);
    printf("==================================================\n");

    return EXIT_SUCCESS;
}
