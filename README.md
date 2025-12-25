# Parallel file operations

## File generator:
- First, I had to generate csv file by running `gcc file_generator.c -o file_generator -lm` (to prevent linker errors), then running it with `./file_generator` to get the csv.


![File Generator](https://github.com/FatihThaDev/parallel-programming/blob/assignment-11/assets/file_generator.png?raw=true)


## Example 1:
- In example 1, only rank 0 performs IO, so data is distributed and collected using MPI, but read and written on rank 0 serially. That means IO is completely serialized and will be slower. I had to run `make` for every iteration to build the executable for a specific version to run it.


  ![Version 1](https://github.com/FatihThaDev/parallel-programming/blob/assignment-11/assets/v1.png?raw=true)


## Example 2:
- In example 2, each process reads its part of the csv seperately, and writes using `MPI_File_write_at`. Now, there is no data aggregation on rank 0, and IO is independent.

- Serial version:


  ![Version 2](https://github.com/FatihThaDev/parallel-programming/blob/assignment-11/assets/v2.png?raw=true)


- MPI version:

  
  ![Version 2 - MPI](https://github.com/FatihThaDev/parallel-programming/blob/assignment-11/assets/v2_2-proc.png?raw=true)


## Example 3:
- In example 3, same computation logic is used like in example 2 (uses `MPI_File_write_all`) and uses explicit MPI-IO hints. It also uses IO aggregators for data . This reduces filysystem contention.


  ![Version 3](https://github.com/FatihThaDev/parallel-programming/blob/assignment-11/assets/v3.png?raw=true)


  - MPI version:

  
  ![Version 3 - MPI](https://github.com/FatihThaDev/parallel-programming/blob/assignment-11/assets/v3_2-proc.png?raw=true)


## Example 4:
- In example 4, each local grid includes halo (ghost) cells used for computations. Only the "real" data should be written to disk, so ghost cells must not appear in the output file. Instead of manually copying data, example 4 uses MPI derived datatypes, to show how data is laid out in memory (with halos), and how data is laid out in the file (with no halos).

  ![Version 4](https://github.com/FatihThaDev/parallel-programming/blob/assignment-11/assets/v4.png?raw=true)
