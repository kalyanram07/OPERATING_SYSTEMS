# Project 02: System Uptime Checker

A core systems utility that queries the Linux kernel to determine exactly how long the operating system has been running continuously since its last boot cycle.

---

## 🧠 Core Operating System Concepts Covered

1. **The Kernel System Statistics Engine (`sys/sysinfo.h`)**
   The Linux kernel continuously updates a global information block tracking hardware and performance metrics. The `sysinfo()` system call acts as a high-performance programmatic bridge that allows user-space utilities to pull live system metrics without interrupting kernel scheduling operations.

2. **Data Representation and Time Conversion**
   The Operating System tracks uptime raw as a total number of elapsed seconds inside a long integer variable (`uptime`). To present this raw data as readable user metrics, the programmer must implement manual timestamp arithmetic to convert seconds into hours, minutes, and remaining seconds.

3. **Memory Buffering via `struct sysinfo`**
   Unlike the system identification strings from Project 1, `sysinfo` yields explicit numeric telemetry data (total RAM, shared memory, free swap space, and uptime counters) packed tightly into specialized system memory structures.

---

## 🛠️ Implementation Details & Compilation

### How to Compile:
```bash
gcc main.c -o uptime_checker
