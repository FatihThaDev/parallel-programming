# Assignment 5 - Vecotrization - Solution
---
## Difference between timestep cpp files explained:
- All three files do the same calculation, but the `#pragma omp simd` line controls how the compiler vectorizes


- **timestep_opt1.c**:
- This tells the compiler to try running the loop with SIMD (single instruction, multiple data)
- It doesn’t say that wavespeed, xspeed, yspeed, and dt are separate for each loop step, so, the compiler might not safely vectorize


- **timestep_opt2.c**:
- Adds `private(wavespeed, xspeed, yspeed, dt)`
- This means each loop iteration has its own copy of these variables
- The compiler can safely run all loop iterations in parallel


- **timestep_opt3.c**:
- Moves these variables inside the loop
- Since they’re declared inside, they’re automatically private (like opt2)
- The code is simpler and cleaner, but still fully optimized for SIMD

  ![Make](https://github.com/FatihThaDev/parallel-programming/blob/assignment-5/assets/make.png?raw=true)
  ![Stream Triad](https://github.com/FatihThaDev/parallel-programming/blob/assignment-5/assets/stream-triad.png?raw=true)
  ![Likwid](https://github.com/FatihThaDev/parallel-programming/blob/assignment-5/assets/likwid-output.png?raw=true)
  ![Vectorized Output](https://github.com/FatihThaDev/parallel-programming/blob/assignment-5/assets/vectorized-output.png?raw=true)

