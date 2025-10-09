==16423== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==16423== Using Valgrind-3.25.1 and LibVEX; rerun with -h for copyright info
==16423== Command: ./main
==16423==
==16423== Invalid write of size 4
==16423==    at 0x40011A2: main (in /home/fatihthedev/Code/parallel-programming/main)
==16423==  Address 0x4a99068 is 0 bytes after a block of size 40 alloc'd
==16423==    at 0x484E7A8: malloc (vg_replace_malloc.c:446)
==16423==    by 0x4001161: main (in /home/fatihthedev/Code/parallel-programming/main)
==16423==
==16423== Conditional jump or move depends on uninitialised value(s)
==16423==    at 0x40011D0: main (in /home/fatihthedev/Code/parallel-programming/main)
==16423==  Uninitialised value was created by a stack allocation
==16423==    at 0x4001149: main (in /home/fatihthedev/Code/parallel-programming/main)
==16423==
==16423== Invalid read of size 4
==16423==    at 0x40011CB: main (in /home/fatihthedev/Code/parallel-programming/main)
==16423==  Address 0x4a99068 is 0 bytes after a block of size 40 alloc'd
==16423==    at 0x484E7A8: malloc (vg_replace_malloc.c:446)
==16423==    by 0x4001161: main (in /home/fatihthedev/Code/parallel-programming/main)
==16423==
==16423==
==16423== HEAP SUMMARY:
==16423==     in use at exit: 40 bytes in 1 blocks
==16423==   total heap usage: 1 allocs, 0 frees, 40 bytes allocated
==16423==
==16423== 40 bytes in 1 blocks are definitely lost in loss record 1 of 1
==16423==    at 0x484E7A8: malloc (vg_replace_malloc.c:446)
==16423==    by 0x4001161: main (in /home/fatihthedev/Code/parallel-programming/main)
==16423==
==16423== LEAK SUMMARY:
==16423==    definitely lost: 40 bytes in 1 blocks
==16423==    indirectly lost: 0 bytes in 0 blocks
==16423==      possibly lost: 0 bytes in 0 blocks
==16423==    still reachable: 0 bytes in 0 blocks
==16423==         suppressed: 0 bytes in 0 blocks
==16423==
==16423== For lists of detected and suppressed errors, rerun with: -s
==16423== ERROR SUMMARY: 14 errors from 4 contexts (suppressed: 0 from 0)

## Steps to solve:
- To fix this, we need to first initialize variables ipos and ival to 0, because variables in C need to be initialized when created, and they weren't.
- Also, we need to free the memory space which pointer iarray took up, because if not, while the program is running, the used up memory space will cause a memory leak.
- Finally, the for loops were faulty, because the array has a size of 10, but for loop went from 0 to 10, and that will make the loop go to 11th index, which doesn't exit, because the array has a size of 10.


==21620== Copyright (C) 2002-2024, and GNU GPL'd, by Julian Seward et al.
==21620== Using Valgrind-3.25.1 and LibVEX; rerun with -h for copyright info
==21620== Command: ./main
==21620==
==21620==
==21620== HEAP SUMMARY:
==21620==     in use at exit: 0 bytes in 0 blocks
==21620==   total heap usage: 1 allocs, 1 frees, 40 bytes allocated
==21620==
==21620== All heap blocks were freed -- no leaks are possible
==21620==
==21620== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
