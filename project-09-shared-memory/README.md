# Project 09: Shared Memory IPC Engine

A low-level inter-process communication application in C that demonstrates high-speed, kernel-bypass memory mapping using POSIX Shared Memory APIs.

## Architecture Highlights
* **Kernel Bypass Channel:** Allows independent processes to read and write data to shared physical RAM without passing parameters through execution system calls.
* **APIs Used:** `shm_open`, `ftruncate`, `mmap`, and `shm_unlink`.

## How to Compile and Run
```bash
gcc shm_producer.c -o shm_producer -lrt
gcc shm_consumer.c -o shm_consumer -lrt
```
