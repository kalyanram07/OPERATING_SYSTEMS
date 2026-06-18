# Project 20: CPU Usage by Process

## Core Architecture
The objective of this project is to implement a programmatic process performance tracker. By opening and parsing the Linux kernel's virtual pseudo-filesystem layout at /proc/self/stat, the engine tokenizes runtime fields to isolate user-mode and kernel-mode jiffies (CPU clock ticks), bypasses third-party monitoring dependencies, and views thread metrics directly from kernel data layers.

## Mechanics Covered
* Virtual Pseudo-Filesystem I/O Parsing
* Kernel Jiffies (Clock Ticks) Demultiplexing
* Tokenized Field Extraction (utime/stime tracking)

## Compilation & Verification
gcc project20_cpu_usage.c -o project20_cpu_usage
./project20_cpu_usage
