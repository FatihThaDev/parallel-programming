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
1. Install `openmpi` package (`sudo pacman -S openmpi` - on ***Arch Linux***)
2. Run `make`
3. Use `mpirun` command to run the code with:
   - 2 processes:

     ![2-processes](https://github.com/FatihThaDev/parallel-programming/blob/assignment-7/assets/2-processes.png?raw=true)


    ```
    parallel-programming on  assignment-7 [?] via C v15.2.1-gcc
    ❯ mpirun -n 2 ./PartialSum
    Main process initializing array of 10000 elements
    Array initialization complete

   Rank 0: processed 5000 elements, partial sum = 12502500.00, compute time = 0.000031 sec

   ========================================
   Timing Results:
     Scatter operation: 0.000164 seconds
     Reduce operation:  0.000027 seconds

   Final Results:
     Total sum across all processes: 50005000.00
   Rank 1: processed 5000 elements, partial sum = 37502500.00, compute time = 0.000034 sec
    ```


   - 4 processes:

     ![4-processes](https://github.com/FatihThaDev/parallel-programming/blob/assignment-7/assets/4-processes.png)


     ```
      parallel-programming on  assignment-7 [?] via C v15.2.1-gcc
      ❯ mpirun -n 4 ./PartialSum
      --------------------------------------------------------------------------
      There are not enough slots available in the system to satisfy the 4
      slots that were requested by the application:
      
        ./PartialSum
      
      Either request fewer procs for your application, or make more slots
      available for use.
      
      A "slot" is the PRRTE term for an allocatable unit where we can
      launch a process.  The number of slots available are defined by the
      environment in which PRRTE processes are run:
      
        1. Hostfile, via "slots=N" clauses (N defaults to number of
           processor cores if not provided)
        2. The --host command line parameter, via a ":N" suffix on the
           hostname (N defaults to 1 if not provided)
        3. Resource manager (e.g., SLURM, PBS/Torque, LSF, etc.)
        4. If none of a hostfile, the --host command line parameter, or an
           RM is present, PRRTE defaults to the number of processor cores
      
      In all the above cases, if you want PRRTE to default to the number
      of hardware threads instead of the number of processor cores, use the
      --use-hwthread-cpus option.
      
      Alternatively, you can use the --map-by :OVERSUBSCRIBE option to ignore the
      number of available slots when deciding the number of processes to
      launch.
      --------------------------------------------------------------------------
     ```

     
   - 8 processes:

     ![8-processes](https://github.com/FatihThaDev/parallel-programming/blob/assignment-7/assets/8-processes.png?raw=true)


     ```
     parallel-programming on  assignment-7 [?] via C v15.2.1-gcc
      ❯ mpirun -n 8 ./PartialSum
      --------------------------------------------------------------------------
      There are not enough slots available in the system to satisfy the 8
      slots that were requested by the application:
      
        ./PartialSum
      
      Either request fewer procs for your application, or make more slots
      available for use.
      
      A "slot" is the PRRTE term for an allocatable unit where we can
      launch a process.  The number of slots available are defined by the
      environment in which PRRTE processes are run:
      
        1. Hostfile, via "slots=N" clauses (N defaults to number of
           processor cores if not provided)
        2. The --host command line parameter, via a ":N" suffix on the
           hostname (N defaults to 1 if not provided)
        3. Resource manager (e.g., SLURM, PBS/Torque, LSF, etc.)
        4. If none of a hostfile, the --host command line parameter, or an
           RM is present, PRRTE defaults to the number of processor cores
      
      In all the above cases, if you want PRRTE to default to the number
      of hardware threads instead of the number of processor cores, use the
      --use-hwthread-cpus option.
      
      Alternatively, you can use the --map-by :OVERSUBSCRIBE option to ignore the
      number of available slots when deciding the number of processes to
      launch.
      --------------------------------------------------------------------------
     ```

     The commands: `mpirun -n 2 ./PartialSum`, `mpirun -n 4 ./PartialSum`, `mpirun -n 4 ./PartialSum`


     Parts of code that need explanation are explained in `PartialSum.c` file:
     - ![scatterv explanation](https://github.com/FatihThaDev/parallel-programming/blob/assignment-7/assets/scatterv.png?raw=true)
     - ![rank0 explanation](https://github.com/FatihThaDev/parallel-programming/blob/assignment-7/assets/rank0.png?raw=true)
