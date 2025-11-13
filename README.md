# Assignment 6 - Solution
---
- My CPU used 4 threads to execute the code
- The main goal of these code iterations is to make parallelization faster and more efficient
- In opt2, each major section (init, flush, stencil) is run with its own pragma `#pragma omp parallel for`
  ![Stencil2](https://github.com/FatihThaDev/parallel-programming/blob/assignment-6/assets/stencil2.png?raw=true)
- in opt4, a single `#pragma omp parallel` wraps the whole loop, which reduces overhead
  ![Stencil4](https://github.com/FatihThaDev/parallel-programming/blob/assignment-6/assets/stencil4.png?raw=true)
- In opt6, work is divied per thread. It adds explicit barriers, which minimizes shared memory conflicts
  ![Stencil6](https://github.com/FatihThaDev/parallel-programming/blob/assignment-6/assets/stencil6.png?raw=true)


- Implicit barrier: happens automatically at the end of `#pragma omp for` or `#pragma omp parallel`. All threads must wait before moving on. It is present in opt2 and opt4.
- Explicit barrier: A barrier written using `#pragma omp barrier`. It is used when you want threads to wait at a specific point. It is present in opt6.
