#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>

int main() {
    const char *shm_name = "/os_sandbox_shm";
    const char *sem_name = "/os_sandbox_sem";
    const int shm_size = 4096;

    int shm_fd = shm_open(shm_name, O_RDONLY, 0666);
    void *ptr = mmap(0, shm_size, PROT_READ, MAP_SHARED, shm_fd, 0);

    sem_t *sem = sem_open(sem_name, 0);
    if (sem == SEM_FAILED) {
        perror("Consumer semaphore open failed. Is producer running?");
        return 1;
    }

    printf("[Consumer]: Checking lock status. Waiting for Producer to finish...\n");
    sem_wait(sem);
    
    printf("[Consumer]: Lock ACQUIRED. Reading safe data: \"%s\"\n", (char *)ptr);

    sem_post(sem);
    sem_close(sem);
    sem_unlink(sem_name);
    shm_unlink(shm_name);
    
    printf("[Consumer]: IPC coordination channels cleanly unlinked from system.\n");

    return 0;
}
