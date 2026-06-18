# Project 19: Process Priority Viewer

## Core Architecture
The objective of this project is to explore the Linux kernel scheduling layer attributes. By invoking POSIX scheduling primitives, the utility targets and extracts the Niceness tracking level of the running process and its parent, revealing how the OS assigns static execution weights during resource contention.

## Mechanics Covered
* Process Niceness Ranges (-20 to 19)
* PRIO_PROCESS Execution Scopes
* Scheduler Attribute Mapping (getpriority)

## Compilation & Verification
gcc project19_priority_viewer.c -o project19_priority_viewer
./project19_priority_viewer
