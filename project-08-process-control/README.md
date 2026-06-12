# Project 08: Process Control Utility

A low-level system administration CLI written in C that controls process thread behaviors using POSIX signals.

## Architecture Highlights
* **Active Regulation:** Targets scheduling states (`SIGSTOP`, `SIGCONT`, `SIGKILL`).
* **Boundary Checked:** Secure CLI token parsing via string evaluations.

## How to Compile and Run
```bash
gcc process_control.c -o process_control
```
