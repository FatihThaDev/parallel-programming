# Parallel Partial Sum Using MPI
---
## This project shows how to divide an array between multiple MPI processes, calculate partial sums on each process, and then combine all results into one total with MPI_Reduce.

The assignment task is to:
- Split a 10,000-element array into pieces
- Give each piece to a different MPI process
- Each process computes its own local sum
- Rank 0 combines all sums into one final total
- Run the code with 2, 4, and 8 processes

## How to Compile:
1. Install `openmpi` package (sudo pacman -S openmpi)
2. Run `make`
3. Use `mpirun` command to run the code with:
   - 2 processes:
     ![2-processes](https://github.com/FatihThaDev/parallel-programming/blob/assignment-7/assets/2-processes.png?raw=true)
   - 4 processes:
     ![4-processes](https://github.com/FatihTheDev/parallel-programming/blob/assignment-7/assets/4-processes.png?raw=true)
   - 4 processes:
     ![8-processes](https://github.com/FatihTheDev/parallel-programming/blob/assignment-7/assets/8-processes.png?raw=true) 
