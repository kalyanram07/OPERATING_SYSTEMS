#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>

int main() {
    const char *shm_name = "/os_sandbox_shm";
    const int shm_size = 4096;
    const char *message = "Hello from the POSIX Shared Memory Producer!";

    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    if (shm_fd == -1) {
        perror("Producer open failure");
        return 1;
    }

    if (ftruncate(shm_fd, shm_size) == -1) {
        perror("Producer resize failure");
        return 1;
    }

    void *ptr = mmap(0, shm_size, PROT_WRITE, MAP_SHARED, shm_fd, 0);
    if (ptr == MAP_FAILED) {
        perror("Producer mapping failure");
        return 1;
    }

    sprintf(ptr, "%s", message);
    printf("[Producer]: Successfully allocated memory and wrote message: \"%s\"\n", message);
    printf("[Producer]: Keeping segment alive. Run the consumer now...\n");

    return 0;
}
