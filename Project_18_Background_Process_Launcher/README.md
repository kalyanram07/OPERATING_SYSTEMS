# Project 18: Background Process Launcher

## Core Architecture
The objective of this project is to implement an asynchronous process spawning utility in C. By bypassing traditional blocking wait() execution gates, the parent process kicks off a task payload and immediately returns execution control to the user interface, simulating how a standard terminal shell processes background tasks via the trailing ampersand (&) operator.

## Mechanics Covered
* Asynchronous Process Instantiation
* Non-blocking Execution Handover
* Decoupled Parent-Child Lifecycles

## Compilation & Verification
gcc project18_background_launcher.c -o project18_background_launcher
./project18_background_launcher
