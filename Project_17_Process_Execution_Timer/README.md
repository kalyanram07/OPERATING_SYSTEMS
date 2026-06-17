# Project 17: Process Execution Timer

## Core Architecture
The objective of this project is to implement a high-resolution process performance benchmarking utility in C. By leveraging the Linux kernel's POSIX monotonic hardware clock (CLOCK_MONOTONIC), the program measures execution duration tracking from fork instantiation to child process termination down to absolute nanosecond precision.

## Mechanics Covered
* High-Resolution Monotonic Clocks (clock_gettime)
* Process Lifecycle Duration Analysis
* Struct timespec Nanosecond Delta Computations

## Compilation & Verification
gcc project17_execution_timer.c -o project17_execution_timer
./project17_execution_timer
