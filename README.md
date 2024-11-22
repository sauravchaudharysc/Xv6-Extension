# Extending xv6 to Limitless Horizons 🌌 🚀 

## Overview
This project extends the capabilities of the **xv6** operating system with key features aimed at improving its functionality and usability. The primary additions include **threads**, **locks**, and the introduction of useful user commands such as `ps` and `clear`. These features make xv6 a more versatile platform for developers and enthusiasts alike, allowing for better multitasking, synchronization, and a cleaner user interface.

## Key Features
- **Threads**: Introduced lightweight threads, enabling concurrent execution of tasks within a process.
- **Locks**: Implemented locks to ensure safe concurrent access to shared resources, preventing race conditions and ensuring thread safety.
- **`ps` Command**: Added a process status command (`ps`) to display a list of all currently running processes, their IDs, and other relevant information.
- **`clear` Command**: Implemented the `clear` command to clear the terminal screen, providing a cleaner workspace.

## Setup
To get started with the extended xv6, follow these instructions to build and run the system.

### Prerequisites
- **Unix-like environment** (Linux, macOS, or Windows with WSL)
- **Make**: Tool for building the operating system

### Steps to Build and Run
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/sauravchaudharysc/Xv6-Extension.git
   cd Xv6-Extension
2. **Open Terminal and Hit make qemu-nox**

3. **Running the Thread and Lock Test: Once xv6 is running, you can test the implementation by running the testthreads program.**

**NOTE:** We are expanding the capabilities of xv6 with exciting new features such as the `ps` and `clear` commands, with more to come. Our goal is to push the boundaries of xv6, transforming it from a foundational operating system into a versatile platform with enhanced functionality and usability for developers and enthusiasts alike.



## From XV6 Authors : 
NOTE: we have stopped maintaining the x86 version of xv6, and switched
our efforts to the RISC-V version
(https://github.com/mit-pdos/xv6-riscv.git)

xv6 is a re-implementation of Dennis Ritchie's and Ken Thompson's Unix
Version 6 (v6).  xv6 loosely follows the structure and style of v6,
but is implemented for a modern x86-based multiprocessor using ANSI C.

ACKNOWLEDGMENTS

xv6 is inspired by John Lions's Commentary on UNIX 6th Edition (Peer
to Peer Communications; ISBN: 1-57398-013-7; 1st edition (June 14,
2000)). See also https://pdos.csail.mit.edu/6.828/, which
provides pointers to on-line resources for v6.

xv6 borrows code from the following sources:
    JOS (asm.h, elf.h, mmu.h, bootasm.S, ide.c, console.c, and others)
    Plan 9 (entryother.S, mp.h, mp.c, lapic.c)
    FreeBSD (ioapic.c)
    NetBSD (console.c)

The following people have made contributions: Russ Cox (context switching,
locking), Cliff Frey (MP), Xiao Yu (MP), Nickolai Zeldovich, and Austin
Clements.

We are also grateful for the bug reports and patches contributed by Silas
Boyd-Wickizer, Anton Burtsev, Cody Cutler, Mike CAT, Tej Chajed, eyalz800,
Nelson Elhage, Saar Ettinger, Alice Ferrazzi, Nathaniel Filardo, Peter
Froehlich, Yakir Goaron,Shivam Handa, Bryan Henry, Jim Huang, Alexander
Kapshuk, Anders Kaseorg, kehao95, Wolfgang Keller, Eddie Kohler, Austin
Liew, Imbar Marinescu, Yandong Mao, Matan Shabtay, Hitoshi Mitake, Carmi
Merimovich, Mark Morrissey, mtasm, Joel Nider, Greg Price, Ayan Shafqat,
Eldar Sehayek, Yongming Shen, Cam Tenny, tyfkda, Rafael Ubal, Warren
Toomey, Stephen Tu, Pablo Ventura, Xi Wang, Keiichi Watanabe, Nicolas
Wolovick, wxdao, Grant Wu, Jindong Zhang, Icenowy Zheng, and Zou Chang Wei.

The code in the files that constitute xv6 is
Copyright 2006-2018 Frans Kaashoek, Robert Morris, and Russ Cox.

ERROR REPORTS

We don't process error reports (see note on top of this file).

BUILDING AND RUNNING XV6

To build xv6 on an x86 ELF machine (like Linux or FreeBSD), run
"make". On non-x86 or non-ELF machines (like OS X, even on x86), you
will need to install a cross-compiler gcc suite capable of producing
x86 ELF binaries (see https://pdos.csail.mit.edu/6.828/).
Then run "make TOOLPREFIX=i386-jos-elf-". Now install the QEMU PC
simulator and run "make qemu".
