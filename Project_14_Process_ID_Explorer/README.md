# Project 14: Process ID Explorer

## Core Architecture
The objective of this project is to intercept and explore deep process ownership attributes and user credentials maintained inside the kernel's Process Control Block (PCB). By invoking POSIX credential primitives, the program reveals the relationship between process execution tracking and operating system security boundaries.

## Mechanics Covered
* Kernel Tracking Identifiers (PID, PPID)
* Real and Effective User IDs (UID, EUID)
* Real and Effective Group IDs (GID, EGID)

## Compilation
gcc project14_process_id_explorer.c -o project14_process_id_explorer
./project14_process_id_explorer
