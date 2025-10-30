# Global Sum Assignment

## What does this code do?
- Shows how different ways to add numbers (summing) can give different results
- Tries four methods: Standard sum, Pairwise sum, Knuth sum, and Kahan sum
- Checks for errors
- Shows how long each method takes

## Why do some ways work better?
- Standard sum is simple, but there is more room for error, because floating points can make the operations more faulty
- Pairwise sum adds numbers in pairs instead of straight order. This helps a bit with the errors, but is still not perfect.
- Knuth and Kahan help fix these mistakes, so they are more efficient

## Sheet link:
- https://docs.google.com/spreadsheets/d/1lL9aipNT3dNz7a31NMronZb_xoPiK04nAPxc8GtMllQ/edit?gid=0#gid=0

## Why does this matter when using many computers?
- When numbers are summed in a different sequence (such as in parallel or high-speed computing), numbers of errors can increase.
- More efficient methods help, but do not fix this problem completely

- **Note**: I also needed to add linker flags, because `pow` was not recognized.

## How to use
- To build: `make`
- To run: `make run`

![Empirical Analysis](https://github.com/FatihThaDev/parallel-programming/blob/assignment-4/assets/empirical-analysis.png?raw=true)
![Sheet Screenshot](https://github.com/FatihThaDev/parallel-programming/blob/assignment-4/assets/sheet-ss.png?raw=true)
