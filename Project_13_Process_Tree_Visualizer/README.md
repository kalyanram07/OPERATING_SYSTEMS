# Project 13: Process Tree Visualizer

## Core Architecture
The objective of this project is to simulate and map a multi-generational process hierarchy tree natively in C. By executing strategic cascading fork routines, a master root parent process creates child and grandchild nodes. Each node identifies its location in the topology by querying its own PID and its parent PPID.

## Mechanics Covered
* Hierarchical Process Generation
* Parent-Child Synchronization via wait blocks
* PID and PPID Network Traversal

## Compilation
gcc project13_process_tree_visualizer.c -o project13_process_tree_visualizer
./project13_process_tree_visualizer
