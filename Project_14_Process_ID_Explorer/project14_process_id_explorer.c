#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    printf("====================================================\n");
    printf("         PROJECT 14: PROCESS ID EXPLORER            \n");
    printf("====================================================\n");

    // Extract core tracking identifiers
    pid_t my_pid = getpid();
    pid_t parent_pid = getppid();

    // Extract security credential attributes
    uid_t real_uid = getuid();
    uid_t eff_uid = geteuid();
    gid_t real_gid = getgid();
    gid_t eff_gid = getegid();

    printf("[PROCESS IDENTITY]\n");
    printf(" -> Current Process ID (PID):       %d\n", my_pid);
    printf(" -> Creator Parent Process ID (PPID): %d\n\n", parent_pid);

    printf("[SECURITY CREDENTIALS]\n");
    printf(" -> Real User ID (UID):             %d\n", real_uid);
    printf(" -> Effective User ID (EUID):       %d\n", eff_uid);
    printf(" -> Real Group ID (GID):            %d\n", real_gid);
    printf(" -> Effective Group ID (EGID):      %d\n\n", eff_gid);

    // Context Evaluation Check
    if (real_uid == 0) {
        printf("[Security State]: Running with administrative ROOT authority.\n");
    } else {
        printf("[Security State]: Running as a standard unprivileged user.\n");
    }

    return 0;
}
