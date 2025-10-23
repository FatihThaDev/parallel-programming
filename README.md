# AoSoA Measurement Project

## What I Fixed

### In the C++ file:
- I added code to create memory for the data:
    ```cpp 
    SoA_type* AoSoA = new SoA_type[num_blocks];
    ```
- I uncommented the lines that fill the arrays with random numbers:
    ```cpp
    AoSoA[j].R[i] = rand();
    AoSoA[j].G[i] = rand();
    AoSoA[j].B[i] = rand();
    ```
- I added code to clean up the memory when done:
    ```cpp
    delete[] AoSoA;
    ```

### In the Makefile:
- I changed `TARGET_SRC` to `aosoa_measurement.cpp`, added tests for 100M, and then ran `make` for all test files:

```bash
LENGTHS = 1 10 100 1000 10000 100000 1000000 10000000 100000000

.PHONY: all clean $(addprefix test_, $(LENGTHS)) test_1K test_10K test_100K test_1M test_10M test_100M
```

```bash
test_1K: test_1000
test_10K: test_10000
test_100K: test_100000
test_1M: test_1000000
test_10M: test_10000000
test_100M: test_100000000
```

```bash
make test_1K
make test_10K  
make test_100K
make test_1M
make test_10M
make test_100M
```
Google Sheet Link:
- https://docs.google.com/spreadsheets/d/1eHZZTmG_VMgnbW0VDsfyoWUZpRQ24yeWHjgtbidA8FI/edit?gid=0#gid=0

![Performance Graph](https://github.com/FatihThaDev/parallel-programming/blob/assignment-3/assets/graph.png?raw=true)
