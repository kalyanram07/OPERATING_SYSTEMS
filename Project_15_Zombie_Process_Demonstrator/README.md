# Project 15: Zombie Process Demonstrator ⭐

## Core Architecture
The objective of this project is to deliberately simulate a process table resource leak by manufacturing a Zombie process. When a child process terminates, its exit status remains allocated inside the kernel process table until the parent explicitly reaps it via wait(). This program shows what happens when a parent neglects this duty.

## Mechanics Covered
* Terminated Process Table Entry Leaks
* Defunct Process State Tracking
* Parent Reaping Obligation Delays

## Compilation & Verification
gcc project15_zombie_demonstrator.c -o project15_zombie_demonstrator
./project15_zombie_demonstrator
