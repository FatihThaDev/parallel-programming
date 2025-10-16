# Task 1 - cairo & hwloc:
---
- I installed `cairo` and `hwlock` packages on my Arch Linux machine using `sudo pacman -S cairo hwloc`.
- Also, I installed `gnuplot`, as defined in the assignment document with `sudo pacman -S gnuplot`.
- Output of `lstopo` command can be found as an attached image in this repository.

# Task 2 - STREAM benchmarking:
---
- I cloned the repository: https://github.com/jeffhammond/STREAM.git
- Before running make, I had to install the gfortran package for it to work: `sudo pacman -S gcc-fortran`.
- I ran `make`, and then executed the executable file stream.exe using command `./stream_c.exe`.

# Task 3 - Roofline Toolkit:
---
- I cloned the repository: https://bitbucket.org/berkeleylab/cs-roofline-toolkit.git, and executed the rest of the steps defined in the assignment task:
  `cd cs-roofline-toolkit/Empirical_Roofline_Tool-1.1.0`
  `cp Config/config.madonna.lbl.gov.01 Config/NameByYourChoice`
- Then, I modified `Config/NameByYourChoice` file to look like this:
```
# Linux workstation, MPI and OpenMP (2-core Intel i3 6006U, 2.00 GHz)

ERT_RESULTS Results.madonna.lbl.gov.01

ERT_DRIVER  driver1
ERT_KERNEL  kernel1

ERT_MPI         True
ERT_MPI_CFLAGS
ERT_MPI_LDFLAGS

ERT_OPENMP         True
ERT_OPENMP_CFLAGS  -fopenmp
ERT_OPENMP_LDFLAGS -fopenmp

ERT_FLOPS   1,2,4

ERT_ALIGN   32

ERT_CC      mpicxx
ERT_CFLAGS  -O3 -march=native -mtune=native -msse4.2 -ffast-math -funroll-loops
ERT_LD      mpicxx
ERT_LDFLAGS
ERT_LDLIBS

ERT_PRECISION FP64

ERT_RUN     export OMP_NUM_THREADS=ERT_OPENMP_THREADS; ERT_CODE

ERT_PROCS_THREADS  1-4
ERT_MPI_PROCS      1
ERT_OPENMP_THREADS 1,2,4

ERT_NUM_EXPERIMENTS 3
ERT_MEMORY_MAX 536870912
ERT_WORKING_SET_MIN 1
ERT_TRIALS_MIN 1

ERT_GNUPLOT gnuplot
```
- Finally, I ran `./ert Config/NameByYourChoice`.
