# GPU Benchmarking

## OpenCL
- As explained in the previous assignment task, my integrated GPU (Intel i3-6006u) is too old to run with OpenCL, as it only supports Intel Gen 8 or higher on Linux.

  ![OCL-Error](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/ocl-error.png?raw=true)

## OpenMP
- The OpenMP version of STREAM can sometimes run on a GPU, but my system has an Intel integrated GPU (6th Gen i3), which is not supported by GCC for GPU offloading on Linux.
-  I had to modify the makefile to run entirely on the CPU using OpenMP, which still allows parallel execution across all CPU cores.

- OpenMP with GPU offloading:
  
   ![OMP-Error](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/omp-error.png?raw=true)


- OpenMP without GPU offloading:
  
   ![OMP-Error](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/omp-cpu.png?raw=true)

  ## CUDA
  - I have an Intel integrated GPU, so I am not able to run with CUDA.

## OpenAcc
- For OpenAcc, I get these results:
  
  ![Openacc](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/openacc.png?raw=true)

- As we can see, the small changes in `StreamTriad_kern1.c`, `StreamTriad_kern2.c`, `StreamTriad_kern3.c` make performance better by implementing directives.
- `StreamTriad_kern1.c` is very slow, because it doesn't utilize directive-based programming.
- `StreamTriad_kern2.c` adds `restrict` keyword, which tells the compiler variable pointers don't overlap and allows for more optimizations.
- `StreamTriad_kern3.c` adds lines `#pragma acc enter data create(a[0:nsize], b[0:nsize], c[0:nsize])` and `#pragma acc exit data delete(...)`. The first starts the dynamic data region after memory allocation, and the second line ends the dynamic data region before memory allocation.
