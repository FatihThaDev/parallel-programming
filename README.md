# Batch Scheduler

- First, I ran `sbatch compute.sh` multiple times to create multiple jobs.

![COmpute](https://github.com/FatihThaDev/parallel-programming/blob/assignment-10/assets/compute.png?raw=true)
  
- As you can see from the screenshot below, the jobs are queued after running the command:

- Then I installed `stress` package with `pacman -S stress`, and ran `./overload.sh`

- I got this output in terminal:

- Then I ran the same, but with 2 cores.

- This is the output I get:

- Then I ran `compute.sh`, without batch scheduler using this command: `salloc --ntasks=1 --cpus-per-task=2`, and as you can see, all the resources are hogged by the `compute.sh`:
