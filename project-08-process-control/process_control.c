#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <stop|resume|kill> <PID>\n", argv[0]);
        return 1;
    }

    char *action = argv[1];
    pid_t target_pid = (pid_t)atoi(argv[2]);

    if (target_pid <= 0) {
        fprintf(stderr, "Error: Invalid Process ID (PID).\n");
        return 1;
    }

    int sig_number = 0;

    if (strcmp(action, "stop") == 0) {
        sig_number = SIGSTOP;
    } else if (strcmp(action, "resume") == 0) {
        sig_number = SIGCONT;
    } else if (strcmp(action, "kill") == 0) {
        sig_number = SIGKILL;
    } else {
        fprintf(stderr, "Error: Unknown action \"%s\". Supported: 'stop', 'resume', or 'kill'.\n", action);
        return 1;
    }

    if (kill(target_pid, sig_number) == 0) {
        printf("Successfully sent signal %d (%s) to Process ID: %d\n", sig_number, action, target_pid);
    } else {
        perror("Signal delivery engine failure");
        return 1;
    }

    return 0;
}
