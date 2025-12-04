# GPU Benchmarking
- For running the benchmark with OpenMP, I ran this command:
  `cmake -DMODEL=omp -B build-omp && cmake --build build-omp`
- I get this output:
  
  ![OMP Output](https://github.com/FatihThaDev/parallel-programming/blob/assignment-8/assets/omp-benchmark.png?raw=true)

- Before running the OpenCL benchmark, I had to install proper OpenCL packages on Arch Linux: `sudo pacman -S opencl-mesa opencl-headers intel-compute-runtime`
- I ran this command:
  
  ```
  cmake -DMODEL=ocl \
      -DOpenCL_LIBRARY=/usr/lib/libOpenCL.so \
      -DOpenCL_INCLUDE_DIR=/usr/include \
      -B build-ocl
  ```
  
- Then I realized that Intel Compute Runtime does not expose OpenCL devices for my GPU, which is an older Intel i3, 6th gen integrated GPU, and Mesa's rusticl only provides OpenCL for Intel gen 8 or newer, so I get this output:
  
![OCL Output](https://github.com/FatihThaDev/parallel-programming/blob/assignment-8/assets/ocl-benchmark.png?raw=true)
