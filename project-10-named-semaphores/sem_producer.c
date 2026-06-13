#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <semaphore.h>

int main() {
    const char *shm_name = "/os_sandbox_shm";
    const char *sem_name = "/os_sandbox_sem";
    const int shm_size = 4096;

    int shm_fd = shm_open(shm_name, O_CREAT | O_RDWR, 0666);
    ftruncate(shm_fd, shm_size);
    void *ptr = mmap(0, shm_size, PROT_WRITE, MAP_SHARED, shm_fd, 0);

    sem_t *sem = sem_open(sem_name, O_CREAT, 0666, 1);
    if (sem == SEM_FAILED) {
        perror("Producer semaphore open failed");
        return 1;
    }

    printf("[Producer]: Requesting lock (sem_wait)...\n");
    sem_wait(sem);
    printf("[Producer]: Lock ACQUIRED. Simulating 5 seconds of intensive data processing...\n");
    
    sleep(5);
    
    sprintf(ptr, "Final Synchronized Payload Stream");
    printf("[Producer]: Data written successfully. Releasing lock (sem_post)...\n");
    
    sem_post(sem);
    sem_close(sem);

    return 0;
}
