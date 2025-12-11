# GPU Benchmarking

## OpenCL
- As explained in the previous assignment task, my integrated GPU (Intel i3-6006u) is too old to run with OpenCL, as it only supports Intel Gen 8 or higher on Linux.

  ![OCL-Error](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/ocl-error.png?raw=true)

## OpenMP
- The OpenMP version of STREAM can sometimes run on a GPU, but my system has an Intel integrated GPU (6th Gen i3), which is not supported by GCC for GPU offloading on Linux.
-  When I try to target the GPU, I get “no devices found.”
-  I had to modify the makefile to run entirely on the CPU using OpenMP, which still allows parallel execution across all CPU cores.

- OpenMP with GPU offloading:
  
   ![OMP-Error](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/omp-error.png?raw=true)


- OpenMP without GPU offloading:
  
   ![OMP-Error](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/omp-cpu.png?raw=true)

## OpenAcc
- For OpenAcc, I get these results:
  ![Openacc](https://github.com/FatihThaDev/parallel-programming/blob/assignment-9/assets/openacc.png?raw=true)
