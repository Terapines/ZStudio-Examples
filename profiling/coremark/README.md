# Coremark

CoreMark is a simple, yet sophisticated benchmark that is designed specifically to test the functionality of a processor core. Running CoreMark produces a single-number score allowing users to make quick comparisons between processors.

## What we change?

We use the "cycle" csr register as the clock source.

## Symbol

You can define the "ITERATIONS" symbol to set loop times and the "SystemCoreClock" symbol to set the CPU frequency (Hz).

## About HTIF

HTIF is a non-standard Berkeley protocol that uses a FIFO non-blocking interface for communication. We can use the HTIF protocol to read and write RTL model memory, load, start, and stop programs, and so on.
