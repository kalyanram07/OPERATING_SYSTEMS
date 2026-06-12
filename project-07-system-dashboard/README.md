# Project 07: Live System Activity Dashboard (Mini-htop)

A low-level system monitoring dashboard written in C that implements real-time, interactive performance metrics tracking inside the Linux terminal environment.

## Architecture Highlights
* **ANSI Terminal Control:** Bypasses heavy fork-exec routines by feeding direct escape sequences (`\033[H\033[J`) to the standard output stream, resulting in a flicker-free screen refresh.
* **High-Precision Differential Math:** Evaluates real-time CPU utilization percentages by sampling delta changes ($\Delta$) in individual process task scheduler cycles against total global hardware cycles over a precise 100ms microsecond window (`usleep`).
* **Dynamic Boundary Safety:** Implements secure character buffer allocations (`char path[512]`) to prevent theoretical format truncation crashes during POSIX absolute path evaluations.

## How to Compile and Run
```bash
gcc system_dashboard.c -o system_dashboard
./system_dashboard
```
