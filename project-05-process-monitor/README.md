# project-05-process-monitor

A minimal C-based process auditing utility that replicates core functionalities of `ps` by tracking active Process IDs (PIDs) inside the Linux kernel virtual filesystem space.

## Concepts Explored
* **Directory Streams (`dirent.h`):** Traversing system directories dynamically using low-level stream loops.
* **Process Identification Mapping:** Isolating active software running inside the Linux kernel context.

