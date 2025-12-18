# Batch Scheduler

- First, I ran `sbatch compute.sh` multiple times to create multiple jobs.

  ![Compute](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/compute.png?raw=true)
  
- As you can see from the screenshot below, the jobs are queued after running the command:

  ![Squeue](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/compute_down.png?raw=true)

- Then I installed `stress` package with `pacman -S stress`, and ran `./overload.sh`

  ![Overload1](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/overload_script_1cpu.png?raw=true)

- I got this output in terminal:

  ![Overload1.1](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/overload_top_1cpu.png?raw=true)

- Then I ran the same, but with 2 cores.

  ![Overload2](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/overload_script_2cpu.png?raw=true)

- This is the output I get:

  ![Overload2.1](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/overload_top_2cpu.png?raw=true)

- Then I ran `compute.sh`, without batch scheduler using this command: `salloc --ntasks=1 --cpus-per-task=2`, and as you can see, all the resources are very much hogged by the `compute.sh`:

  ![ComputeWoS](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/compute_without_scheduler_2cpu.png?raw=true)
