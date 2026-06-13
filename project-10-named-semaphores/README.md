# Project 10: Named Semaphores Coordination Engine

A low-level process synchronization application in C that implements Mutual Exclusion (Mutex) across independent system threads using POSIX Named Semaphores.

## Architecture Highlights
* **Race Condition Prevention:** Restricts concurrent access to memory segments using binary flag gating.
* **Asynchronous Blocking Architecture:** Coordinates task schedules natively using kernel queues via `sem_wait` and `sem_post`.

## How to Compile and Run
```bash
gcc sem_producer.c -o sem_producer -lrt -pthread
gcc sem_consumer.c -o sem_consumer -lrt -pthread
```
