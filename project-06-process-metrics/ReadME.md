# Project 06: Process Resource Utilization Tracker

A low-level Linux systems utility written in C that extracts core hardware metrics and processing workloads directly from the kernel virtual filesystem namespace (`procfs`).

## Core Architecture
This diagnostic tool interfaces directly with POSIX subsystem abstractions to parse runtime performance metrics:
* **Memory Tracking:** Dynamically reads `/proc/[PID]/status` to map physical RAM residency (`VmRSS`) allocations.
* **CPU Auditing:** Scans space-separated data tracks in `/proc/[PID]/stat` to calculate accumulative scheduler clock cycles (`utime`, `stime`, `cutime`, `cstime`).

## How to Run
```bash
gcc process_metrics.c -o process_metrics
./process_metrics