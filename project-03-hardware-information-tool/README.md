# Project 03: Hardware Information Tool (Day 3)

A low-level systems architecture utility written in native C for Linux/WSL environments. This tool bypasses standard user-space abstractions to hook into the Linux kernel virtual filesystem layer, parsing raw hardware telemetry dynamically.

## Core OS Concepts Covered

### 1. The /proc Virtual Subsystem
Unlike traditional files stored on a physical disk module, files inside the /proc directory are generated dynamically by the Linux kernel on demand. They serve as an internal look into the kernel data structures.
* /proc/cpuinfo: Polled by the OS to fetch the active processor string matrices and CPU core mapping layouts.
* /proc/meminfo: Polled to track real-time physical page frame memory statistics (volatile RAM modules).

### 2. Runtime Token Parsing & Core Density Logic
The operating system abstracts logical hardware threads using text block strings. This utility tracks hardware density by scanning for the processor delimiter tag inside the kernel stream to count total active logical processor units available to the OS task scheduler.

---

## Compilation and Execution

To compile and run this systems utility natively inside your Linux shell, run:

gcc main.c -o hardware_tool
./hardware_tool
