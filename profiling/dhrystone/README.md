# Dhrystone

Dhrystone is a synthetic computing benchmark program developed in 1984 by Reinhold P. Weicker intended to be representative of system (integer) programming. The Dhrystone grew to become representative of general processor (CPU) performance. The name "Dhrystone" is a pun on a different benchmark algorithm called Whetstone, which emphasizes floating point performance.

## What we change?

1. We compute mcycle, minstret at the beginning and end of the program iteration and print the difference as the result.
2. Merge several files of dhrystone into one.

## Symbol

You can define the "NUMBER_OF_RUNS" symbol to set loop times.

## About HTIF

HTIF is a non-standard Berkeley protocol that uses a FIFO non-blocking interface for communication. We can use the HTIF protocol to read and write RTL model memory, load, start, and stop programs, and so on.
