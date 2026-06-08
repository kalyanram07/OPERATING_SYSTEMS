# Project 01: OS Information Viewer

A system utility that directly queries the Linux kernel to retrieve the system name, network node hostname, operating system release version, and underlying hardware architecture.

---

## 🧠 Core Operating System Concepts Covered

1. **The Kernel-User Space Interface (`sys/utsname.h`)**
   The application space cannot directly access kernel memory variables for security reasons. To find out what OS is running, the program triggers a programmatic bridge using the `uname()` system call, allowing user-space applications to read specific kernel data safely.

2. **Data Serialization via Structures (`struct`)**
   The Operating System returns a complex bundle of values inside a single data container called a `struct`. Understanding how memory fields (`sysname`, `release`, `machine`) are packed within a continuous system structure is essential for hardware-level firmware development.

3. **System Errors and Diagnostics (`perror`)**
   If a system call fails (e.g., due to restricted context or corrupted environment arrays), checking the global `errno` code using `perror` allows the programmer to find out exactly why the operating system rejected the request.

---

## 🛠️ Implementation Details & Compilation

### How to Compile:
```bash
gcc main.c -o os_viewer
