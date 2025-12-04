# GPU Benchmarking
- For running the benchmark with OpenMP, I ran this command:
  `cmake -DMODEL=omp -B build-omp && cmake --build build-omp`
- I get this output:
  ❯ ./omp-stream
  BabelStream
  Version: 5.0
  Implementation: OpenMP
  Running kernels 100 times
  Precision: double
  Array size: 268.4 MB (=0.3 GB)
  Total size: 805.3 MB (=0.8 GB)
  Init: 0.232348 s (=3465.942859 MBytes/sec)
  Read: 1.263412 s (=637.405739 MBytes/sec)
  Function    MBytes/sec  Min (sec)   Max         Average
  Copy        7999.851    0.06711     0.13300     0.07992
  Mul         7911.424    0.06786     0.15067     0.08073
  Add         8876.346    0.09072     0.17044     0.10304
  Triad       8966.498    0.08981     0.15799     0.10313
  Dot         14100.431   0.03807     0.09010     0.05035

- Before running the OpenCL benchmark, I had to install proper OpenCL packages on Arch Linux: `sudo pacman -S opencl-mesa opencl-headers intel-compute-runtime`
- Then I realized that Intel Compute Runtime does not expose OpenCL devices for my GPU, which is an older Intel i3, 6th gen integrated GPU, and Mesa's rusticl only provides OpenCL for Intel gen 8 or newer, so I get this output:
  ❯ ./ocl-stream
  BabelStream
  Version: 5.0
  Implementation: OpenCL
  Running kernels 100 times
  Precision: double
  Array size: 268.4 MB (=0.3 GB)
  Total size: 805.3 MB (=0.8 GB)
  terminate called after throwing an instance of 'cl::Error'
    what():  clGetPlatformIDs
  [1]    18905 IOT instruction (core dumped)  ./ocl-stream
