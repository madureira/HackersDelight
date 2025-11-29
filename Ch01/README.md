# Chapter 1 - Introduction

## Exercises

1\. Express the loop

```math
\text{for}\ (e_1;\ e_2;\ e_3)\ \text{statement}
```

in terms of a `while` loop.

Can it be expressed as a `do` loop?

**Answer:**

```math
\begin{aligned}
& e_1; \\
& \text{while } (e_2)\ \{ \\
& \qquad \text{statement} \\
& \qquad e_3; \\
& \}
\end{aligned}
```

With `do while`:

```math
\begin{aligned}
& e_1; \\
& \text{if (}e_2\text{) \{ } \\
& \qquad \text{do}\ \{ \\
& \qquad\qquad \text{statement} \\
& \qquad\qquad e_3\text{;} \\
& \qquad \text{\} while (}e_2\text{);} \\
& \}
\end{aligned}
```

2\. Code a loop in C in which the unsigned integer control variable **_i_** takes on all values from 0 to and including the maximum unsigned number, `0xFFFFFFFF` (on a 32-bit machine).

**Answer:**

[exe_2.c](/Ch01/exe_2.c)

3\. For the more experienced reader: The instruction of the basic and full RISCs defined in this book can be executed with at most two register reads and one write. What are some common or plausible RISC instructions that either need more source operands or need more than one register write?
