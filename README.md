# GPU Benchmarking

## OpenCL
---
- As explained in the previous assignment task, my integrated GPU (Intel i3-6006u) is too old to run with OpenCL, as it only supports gen 8 or higher on Linux.

## OpenMP
---
- The OpenMP version of STREAM can so run on a GPU. However, my system has an Intel integrated GPU (6th Gen i3), which is not supported by GCC for GPU offloading on Arch.
-  When I try to target the GPU, I get “no devices found.”
-  The program runs entirely on the CPU using OpenMP, which still allows parallel execution across all CPU cores.

  ![OMP-Error](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/omp-error.png?raw=true)
