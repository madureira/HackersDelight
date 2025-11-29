# Chapter 1 - Introduction

## Exercises

1\. Express the loop

```math
for (e_1;\ e_2;\ e_3)\ statement
```

in terms of a `while` loop.

Can it be expressed as a do loop?

**Answer:**

```math
\begin{array}{l}
\text{} e_1\text{;} \\
\text{while (}e_2\text{) \{ } \\
\text{\qquad statement} \\
\text{\qquad }e_3\text{;} \\
\text{\}}
\end{array}
```

do while:

```math
\begin{array}{l}
\text{} e_1\text{;} \\
\text{if (}e_2\text{) \{ } \\
\text{\qquad do \{} \\
\text{\qquad\qquad }statement \\
\text{\qquad\qquad }e_3\text{;} \\
\text{\qquad \} while (}e_2\text{);} \\
\text{\}}
\end{array}
```

2\. Code a loop in C in which the unsigned integer control variable **_i_** takes on all values from 0 to and including the maximum unsigned number, `0xFFFFFFFF` (on a 32-bit machine).

3\. For the more experienced reader: The instruction of the basic and full RISCs defined in this book can be executed with at most two register reads and one write. What are some common or plausible RISC instructions that either need more source operands or need more than one register write?
