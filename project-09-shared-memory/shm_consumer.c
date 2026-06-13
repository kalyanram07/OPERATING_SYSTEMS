#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    const char *shm_name = "/os_sandbox_shm";
    const int shm_size = 4096;

    int shm_fd = shm_open(shm_name, O_RDONLY, 0666);
    if (shm_fd == -1) {
        perror("Consumer open failure. Is producer running?");
        return 1;
    }

    void *ptr = mmap(0, shm_size, PROT_READ, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Consumer mapping failure");
        return 1;
    }

    printf("[Consumer]: Read payload directly from shared RAM memory area: \"%s\"\n", (char *)ptr);

    if (shm_unlink(shm_name) == -1) {
        perror("Consumer unlink failure");
        return 1;
    }
    printf("[Consumer]: Shared memory segments cleanly torn down and removed from kernel.\n");

    return 0;
}
