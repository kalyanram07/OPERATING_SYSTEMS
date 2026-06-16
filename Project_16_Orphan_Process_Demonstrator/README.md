# Project 16: Orphan Process Demonstrator ⭐

## Core Architecture
The objective of this project is to explicitly demonstrate parent-child termination inversion by manufacturing an Orphan process. When a creator parent process exits early, its running children lose their tracking context anchor. The Linux kernel handles this by automatically re-parenting the orphan to the root initialization daemon (systemd/init), changing its PPID to 1 or a sub-reaper proxy.

## Mechanics Covered
* Init/Systemd Root Process Adoption
* Parent Termination Inversion States
* Dynamic PPID Re-allocation Tracking

## Compilation & Verification
gcc project16_orphan_demonstrator.c -o project16_orphan_demonstrator
./project16_orphan_demonstrator
