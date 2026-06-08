# 🛠️ Advanced Operating Systems: 100-Project Masterclass

Welcome to my core Systems Programming and Operating Systems tracking repository. This portfolio is a systematic, hands-on deep dive into low-level engineering, kernel architectures, and resource management. 

## 🎯 The Core Mission
* **Velocity:** Completing **1 project per day** with rigorous code implementation and structural documentation.
* **Target Focus:** Specialized technical preparation for top-tier silicon and systems companies like **Qualcomm**.
* **Language:** Pure C, utilizing native system APIs to bridge the gap between user space and kernel space.

---

These 15 critical implementations are highlighted with a ⭐ across the catalog. They cover the fundamental low-level architecture domains frequently evaluated in technical system design interviews.

1. **Project 98:** Mini Linux/Windows Shell (Process Control, Exec Environments)
2. **Project 15:** Zombie Process Demonstrator (Process Lifecycle & State Tables)
3. **Project 16:** Orphan Process Demonstrator (Parent-Child Tracking Inversion)
4. **Project 13:** Process Tree Visualizer (DFS Kernel Tree Traversal)
5. **Project 31:** Producer-Consumer Problem (Bounded-Buffer Synchronization)
6. **Project 32:** Reader-Writer Problem (Shared Resource Concurrency Constraints)
7. **Project 33:** Dining Philosophers Problem (Resource Contention Mechanics)
8. **Project 50:** Banker's Algorithm (Deadlock Avoidance & Safe State Evaluation)
9. **Project 58:** Round-Robin Scheduler (Time-Slicing & Context Switching)
10. **Project 69:** Memory Leak Detector (Dynamic Allocation Tracking Engine)
11. **Project 70:** Paging Simulator (Virtual-to-Physical Address Translation)
12. **Project 76:** LRU Page Replacement (Cache/Memory Eviction Algorithms)
13. **Project 91:** Pipe Communication (Inter-Process Data Streams & Anonymous IPC)
14. **Project 99:** System Call Explorer (Deep Tracing of Core Kernel Interrupts)
15. **Project 100:** Smart System Monitor (High-Performance Real-Time System Telemetry)

---

## 📊 Complete 100-Project Implementation Roadmap

### 🖥️ UNIT 1: Introduction to OS (Projects 1–10)
*Core Concepts: Kernel-User Interfaces, Subsystem Telemetry, System Calls, REPL Frameworks.*

- [x] **Project 01: OS Information Viewer** (`sys/utsname.h` / `windows.h`) → *Concepts: Kernel Space Bridging, Machine Target Architectures*
- [x] **Project 02: System Uptime Checker** (`sys/sysinfo.h` / `GetSystemTime`) → *Concepts: Kernel Monotonic Timers, System Telemetry Arithmetic*
- [ ] **Project 03: Hardware Information Tool** → *Concepts: CPU Topology, Physical RAM Capacities, Page Allocation Limits*
- [ ] **Project 04: User Information Utility** → *Concepts: Environmental Context Variables, Secure UID/SID Identification Lookup*
- [ ] **Project 05: Process Counter** → *Concepts: Kernel Proctable/Object Scraping, Directory Streams*
- [ ] **Project 06: Memory Usage Monitor** → *Concepts: Ram footprint analytics, Shared Memory Boundary Layouts*
- [ ] **Project 07: Disk Usage Analyzer** → *Concepts: File System Metadata Parsing, Sector/Cluster Mapping*
- [ ] **Project 08: Command-Line Calculator** → *Concepts: User Space Interactive String Parsing, Logic Execution Buffers*
- [ ] **Project 09: System Resource Dashboard** → *Concepts: Monolithic Diagnostics Aggregation, Data Struct Integration*
- [ ] **Project 10: Mini Terminal Prompt** → *Concepts: Interactive REPL Loop Mechanics, Standard Input Stream Trailing*

### ⚙️ UNIT 2: Processes (Projects 11–25)
*Core Concepts: Forking, Execution Layout Morphing, Process Lifecycle States, Task Management.*

- [ ] **Project 11: Process Creator** → *Concepts: Process Context Cloning, Process Control Blocks (PCB)*
- [ ] **Project 12: Parent-Child Process Demo** → *Concepts: Execution Divergence, Isolated PID Return Tracking*
- [ ] **Project 13: Process Tree Visualizer ⭐** → *Concepts: Tree Data Structures, Parent-Child Hierarchical Maps*
- [ ] **Project 14: Process ID Explorer** → *Concepts: Kernel Tracking IDs (PID, PPID), Process Credentials*
- [ ] **Project 15: Zombie Process Demonstrator ⭐** → *Concepts: Terminated Process Table Entry Leaks, Exit Codes, `wait()` Delays*
- [ ] **Project 16: Orphan Process Demonstrator ⭐** → *Concepts: Init/Systemd Process Adoption, Parent Termination Inversion*
- [ ] **Project 17: Process Execution Timer** → *Concepts: High-Resolution Monotonic Clocks, Context Tracking Duration*
- [ ] **Project 18: Background Process Launcher** → *Concepts: Asynchronous Execution, Asynchronous Signal Detachment*
- [ ] **Project 19: Process Priority Viewer** → *Concepts: Process Niceness Levels, Static Scheduling Attributes*
- [ ] **Project 20: CPU Usage by Process** → *Concepts: Kernel Jiffies Parsing, Thread Running Metrics*
- [ ] **Project 21: Process Killer Utility** → *Concepts: Kernel Inter-Process Signals (`SIGKILL`, `SIGTERM` / `TerminateProcess`)*
- [ ] **Project 22: Process Search Tool** → *Concepts: String Filters across Process Table Images*
- [ ] **Project 23: Child Process Counter** → *Concepts: Parent-Owned Process Family Ingestion*
- [ ] **Project 24: Process Lifecycle Simulator** → *Concepts: State Machine Tracking (Ready, Running, Blocked, Terminated)*
- [ ] **Project 25: Mini Task Manager** → *Concepts: Consolidated Process List Render Engines*

### 🔄 UNIT 3: Threads (Projects 26–35)
*Core Concepts: Lightweight Processes, Shared Address Spaces, Parallelization, Classical Concurrency Problems.*

- [ ] **Project 26: Create Single Thread** → *Concepts: Thread Stack Allocation, Thread Control Blocks (TCB)*
- [ ] **Project 27: Multi-threaded Counter** → *Concepts: Concurrency Execution Overlap, Memory interleaving*
- [ ] **Project 28: Parallel Array Sum** → *Concepts: Data Partitioning, Multicore Parallel Chunking Processing*
- [ ] **Project 29: Thread ID Viewer** → *Concepts: Thread Identification Context Mapping (TID)*
- [ ] **Project 30: Thread Synchronization Demo** → *Concepts: Race Interdiction Basics, Thread Join Mechanics*
- [ ] **Project 31: Producer Consumer ⭐** → *Concepts: Bounded-Buffer Concurrency, Buffer Exhaustion Strategies*
- [ ] **Project 32: Reader Writer ⭐** → *Concepts: Resource Lock Shared/Exclusive Starvation Mechanics*
- [ ] **Project 33: Dining Philosophers ⭐** → *Concepts: Resource Allocation Overlap, Asymmetric Resource Acquisition*
- [ ] **Project 34: Parallel Matrix Addition** → *Concepts: 2D Memory Array Splitting, Grid-Based Thread Maps*
- [ ] **Project 35: Thread Pool Simulator** → *Concepts: Pre-allocated Worker Queues, Task Dispatch Engines*

### 🔒 UNIT 4: Synchronization (Projects 36–45)
*Core Concepts: Mutexes, Semaphores, Critical Sections, Race Prevention Algorithms.*

- [ ] **Project 36: Semaphore Demo** → *Concepts: Counting Semaphores, Resource Pooling Control Limits*
- [ ] **Project 37: Mutex Demo** → *Concepts: Binary Locks, Priority Inversion Safeguards, Lock Ownership*
- [ ] **Project 38: Critical Section Simulation** → *Concepts: Exclusive Execution Code Bounds, Memory Walls*
- [ ] **Project 39: Race Condition Example** → *Concepts: Non-atomic Memory Interleaving Fault Analysis*
- [ ] **Project 40: Peterson's Algorithm** → *Concepts: Software-Level Mutual Exclusion (Strict Alternation, Turn Variables)*
- [ ] **Project 41: Binary Semaphore Example** → *Concepts: Strict Flag Signalling Systems across Processing Boundaries*
- [ ] **Project 42: Resource Lock Manager** → *Concepts: Token-Based Multi-Resource Synchronization Grids*
- [ ] **Project 43: Shared Counter Protection** → *Concepts: Atomic Assembly Operations, Variable Lock Wrappers*
- [ ] **Project 44: Multi-thread Bank Account** → *Concepts: Complex Transaction Atomicity Checks, Rollback Safety*
- [ ] **Project 45: Traffic Signal Synchronization** → *Concepts: State Timing Synchronization, Conditional Signal Flags*

### 💀 UNIT 5: Deadlocks (Projects 46–55)
*Core Concepts: Mutual Exclusion, Hold and Wait, No Preemption, Circular Wait, Avoidance and Recovery.*

- [ ] **Project 46: Deadlock Simulator** → *Concepts: Creating Circular Wait Locks via Interlaced Acquisition*
- [ ] **Project 47: Resource Allocation Table** → *Concepts: Dynamic Matrix Representations of Claim/Allocation Maps*
- [ ] **Project 48: Safe State Checker** → *Concepts: Multi-Resource Dependency Graph Parsing*
- [ ] **Project 49: Unsafe State Detector** → *Concepts: Predictive Starvation Edge-Case Tracking*
- [ ] **Project 50: Banker's Algorithm ⭐** → *Concepts: Safety Vector Check Loops, Resource Claim Avoidance Algorithms*
- [ ] **Project 51: Deadlock Detection Tool** → *Concepts: Cycle Detection Algorithms in Resource Allocation Graphs (RAG)*
- [ ] **Project 52: Deadlock Recovery Simulator** → *Concepts: Process Preemption, State Rollback Management*
- [ ] **Project 53: Resource Request Visualizer** → *Concepts: Matrix Telemetry Updates of Outstanding Demands*
- [ ] **Project 54: Dining Philosophers with Deadlock** → *Concepts: Symmetric Acquisition-Induced Total System Lock*
- [ ] **Project 55: Deadlock-Free Dining Philosophers** → *Concepts: Arbitrary Resource Ordering / Resource Preemption Rules*

### 🧠 UNIT 6: CPU Scheduling (Projects 56–65)
*Core Concepts: Scheduling Optimization Metrics, Multi-Queue Management, Real-Time Scheduling Algorithms.*

- [ ] **Project 56: FCFS Scheduler** → *Concepts: Non-Preemptive Queue Processing, Convoy Effect Vulnerabilities*
- [ ] **Project 57: SJF Scheduler** → *Concepts: Burst-Time Optimization, Starvation Vectors for Long Jobs*
- [ ] **Project 58: Round Robin Scheduler ⭐** → *Concepts: Quantum Time Slicing, Interrupt-Driven Context Switches*
- [ ] **Project 59: Priority Scheduler** → *Concepts: Weighted Task Execution Scheduling, Dynamic Aging Strategies*
- [ ] **Project 60: Preemptive Priority Scheduler** → *Concepts: Dynamic Interrupt Eviction, Running Process Context Saving*
- [ ] **Project 61: Multilevel Queue Scheduler** → *Concepts: Foreground/Background Target Splitting, Priority Demotion Rules*
- [ ] **Project 62: Waiting Time Calculator** → *Concepts: Metric Compilations (End Time - Arrival Time - Burst)*
- [ ] **Project 63: Turnaround Time Calculator** → *Concepts: Complete Duration Lifecycle Telemetry Analytics*
- [ ] **Project 64: Scheduling Visualizer** → *Concepts: Gantt Chart String Rendering Engines*
- [ ] **Project 65: AI-Based Scheduler (Advanced)** → *Concepts: Pattern-Based Core Assignment Estimations*

### 💾 UNIT 7: Memory Management (Projects 66–80)
*Core Concepts: Virtual Memory, Address Translation, Segmentation, Page Replacement Engines.*

- [ ] **Project 66: Stack vs Heap Demonstrator** → *Concepts: Stack Frames, Heap Free-Lists, Growth Vectors*
- [ ] **Project 67: Memory Allocator Simulator** → *Concepts: First-Fit, Best-Fit, Worst-Fit Space Management*
- [ ] **Project 68: malloc/free Tracker** → *Concepts: Global Heap Overhead Tracking, Metadata Wrappers*
- [ ] **Project 69: Memory Leak Detector ⭐** → *Concepts: Allocation-Free Mismatch Analyzers, Memory Map Auditing*
- [ ] **Project 70: Paging Simulator ⭐** → *Concepts: Page Tables, Virtual Page Numbers (VPN), Offset Math*
- [ ] **Project 71: Segmentation Simulator** → *Concepts: Logical Group Variable Chunks, Segment Base/Limit Tables*
- [ ] **Project 72: Address Translation Tool** → *Concepts: MMU Simulation, Multi-Level Bitmask Bitshifting Operations*
- [ ] **Project 73: Virtual Memory Simulator** → *Concepts: Swap Files, Secondary Storage Backed Page Frames*
- [ ] **Project 74: Page Fault Counter** → *Concepts: Miss Ratios, Interrupt Traps for Non-Resident Memory Blocks*
- [ ] **Project 75: FIFO Page Replacement** → *Concepts: First-In-First-Out Eviction Cache Lines, Belady’s Anomaly*
- [ ] **Project 76: LRU Page Replacement ⭐** → *Concepts: Temporal Locality Optimization, Usage History Vectors*
- [ ] **Project 77: Optimal Page Replacement** → *Concepts: Look-Ahead Algorithms (Theoretical Maximum Efficiency Benchmark)*
- [ ] **Project 78: TLB Simulator** → *Concepts: Translation Lookaside Buffer Caching, Hit/Miss Pipeline Evaluation*
- [ ] **Project 79: Memory Fragmentation Visualizer** → *Concepts: Internal vs External Fragmentation Overhead Maps*
- [ ] **Project 80: Custom Memory Manager** → *Concepts: Fixed-Size Block Pools, Overriding Standard Allocators*

### 📂 UNIT 8: File Systems (Projects 81–90)
*Core Concepts: File Discriptors, Directory Infrastructures, Metadata Parsing, Compression Buffers.*

- [ ] **Project 81: File Creator** → *Concepts: Create Flags, File Allocation Tables, Directory Allocation*
- [ ] **Project 82: File Reader** → *Concepts: Direct I/O Read Streams, Buffer Slices*
- [ ] **Project 83: File Writer** → *Concepts: Write Append Inodes, Persistence Serialization Layouts*
- [ ] **Project 84: File Copy Utility** → *Concepts: Inter-Buffer Pipeline Processing Streams*
- [ ] **Project 85: File Search Tool** → *Concepts: Deep File Descriptor Text Pattern Traversal*
- [ ] **Project 86: Directory Tree Viewer** → *Concepts: Hierarchical Directory Traversal, Inode Structural Crawling*
- [ ] **Project 87: Duplicate File Detector** → *Concepts: Hash Checksum Compilations, File Size Matching Grids*
- [ ] **Project 88: File Permission Checker** → *Concepts: POSIX Mode Bitmasks (`rwxrwxrwx`) / Windows Access Control Lists*
- [ ] **Project 89: Mini File Manager** → *Concepts: High-Level Combined Actions (Move, Copy, Rename, Destroy)*
- [ ] **Project 90: File Compression Simulator** → *Concepts: Encoding Pipelines, Compact File Serialization Blocks*

### 🌐 UNIT 9: IPC (Projects 91–97)
*Core Concepts: Communication Channels, Inter-Process Data Pipelines, Shared Segments.*

- [ ] **Project 91: Pipe Communication ⭐** → *Concepts: Unidirectional Streams, Kernel Buffer Piping, File Descriptor Clones*
- [ ] **Project 92: Named Pipe Demo** → *Concepts: FIFO Files, Independent Non-Related Process IPC Handles*
- [ ] **Project 93: Shared Memory Demo** → *Concepts: Concurrent Address Space Mapping, Zero-Copy IPC Channels*
- [ ] **Project 94: Message Queue Example** → *Concepts: Structured Packet Queues, Kernel-Managed Message Routing*
- [ ] **Project 95: Socket-Based Chat** → *Concepts: Network Protocol Layer Interface, Loopback Adapters (`127.0.0.1`)*
- [ ] **Project 96: Parent-Child IPC** → *Concepts: Local Domain Socket Pairs / Anonymous Pipes*
- [ ] **Project 97: Multi-Client Communication** → *Concepts: Non-Blocking Concurrent Socket Connection Arrays*

### 🚀 UNIT 10: System Programming Projects (98–100)
*Core Concepts: Large-scale Infrastructure Engineering, Deep Kernel Hook Consolidation.*

- [ ] **Project 98: Mini Linux/Windows Shell ⭐** → *Concepts: Complete REPL, Token Parsing, Process Forking, Process Lifecycle Tracking*
- [ ] **Project 99: System Call Explorer ⭐** → *Concepts: Inline Assembler, Software Interrupt Traps, High-Fidelity Diagnostics*
- [ ] **Project 100: Smart System Monitor ⭐** → *Concepts: High-Performance Integrated CPU, RAM, Disk, and Process Profiling*

---

## 🛠️ How to Compile and Run the Ecosystem
Each project directory contains a separate source setup file. The uniform compile format used is:

```bash
# Enter desired project folder
cd project-xx-name-convention

# Compile
gcc main.c -o program_executable

# Execute
./program_executable