# Chapter 2 - BASICS

## 2-1 Manipulating Rightmost Bits

Use the following formula to turn off the rightmost 1-bit in a word, producing 0 if none (eg., 01011000 $`\Rightarrow`$ 01010000):

```math
x\ \&\ (x - 1)
```

This can be used to determine if an unsigned integer is a power of 2 or is 0: apply the formula followed bya a 0-test on the resut.

*Demo:* [basics_01.c](/Ch02/basics_01.c)

---

Use the following formula to turn on the rightmost 0-bit in a word, producing all 1's if none (e.g., 10100111 $`\Rightarrow`$ 10101111):

```math
x\ |\ (x + 1)
```

*Demo:* [basics_02.c](/Ch02/basics_02.c)

---

Use the following formula to turn off the trailing 1's in a word, producing $`x`$ if none (e.g., 10100111 $`\Rightarrow`$ 10100000):

```math
x\ \&\ (x + 1)
```

This can be used to determine if an unsigned integer is of the form $`2^n - 1`$, 0, or all 1's: apply the formula followed by 0-test on the result.

*Demo:* [basics_03.c](/Ch02/basics_03.c)

---

Use the following formula to turn on the trailing 0's in a word, producing $`x`$ if none (e.g., 10101000 $`\Rightarrow`$ 10101111):

```math
x\ |\ (x - 1)
```

*Demo:* [basics_04.c](/Ch02/basics_04.c)

---

Use the following formula to create a word with a single 1-bit at the position of the rightmost 0-bit in $`x`$, producing 0 if none (e.g., 10100111 $`\Rightarrow`$ 00001000):

```math
\neg x\ \&\ (x + 1)
```

*Demo:* [basics_05.c](/Ch02/basics_05.c)

---

Use the following formula to create a word with a single 0-bit at the position of the rightmost 1-bit in $`x`$, producing all 1's if none (e.g., 10101000 $`\Rightarrow`$ 11110111):

```math
\neg x\ |\ (x - 1)
```

*Demo:* [basics_06.c](/Ch02/basics_06.c)

---

Use one of the following to create a word with 1's at the position of the trailing 0's i $`x`$, and 0's elsewhere, producing 0 if none (e.g., 01011000 $`\Rightarrow`$ 00000111):

```math
\begin{array}{r}
\neg x\ \mathbin{\&}\ (x - 1)          & \text{, or}\\
\ \neg (x\ \mathbin{|} \mathord{-}\!x)   & \text{, or}\\
(x\ \mathbin{\&}\ \mathord{-}\!x) - 1  &
\end{array}
```

The first formula has some instruction-level parallelism.

*Demo:* [basics_07.c](/Ch02/basics_07.c)

---

Use following formula to create a word with 0's at the positions of the trailing 1's in $`x`$, and 1's elsewhere, producing all 1's if none (e.g., 10100111 $`\Rightarrow`$ 11111000):

```math
\neg x\ \mathbin{|}\ (x + 1)
```

*Demo:* [basics_08.c](/Ch02/basics_08.c)

---

Use the following formula to isolate the rightmost 1-bit, producing 0 if none (e.g., 01011000 $`\Rightarrow`$ 00001000):

```math
x\ \&\ (\mathord{-}\!x)
```

*Demo:* [basics_09.c](/Ch02/basics_09.c)

---

Use the following formula to create a word with 1's at the positions of the rightmost 1-bit and the trailing 0's in $`x`$, producing all 1's if no 1-bit, and the integer 1 if no trailing 0's (e.g., 01011000 $`\Rightarrow`$ 000011111):

```math
x \oplus  (x-1)
```

*Demo:* [basics_10.c](/Ch02/basics_10.c)

---

Use the following formula to create a word with 1's at the positions of the rightmost 0-bit and the trailing 1's in $`x`$, producing all 1's if no 0-bit, and the integer 1 if no trailing 1's (e.g., 01010111 $`\Rightarrow`$ 00001111):

```math
x \oplus (x+1)
```

*Demo:* [basics_11.c](/Ch02/basics_11.c)

---

Use either of the following formulas to turn off the rightmost contiguous string of 1's (e.g., 01011100 $`\Rightarrow`$ 01000000) [Wood]:

```math
\begin{array}{r}
(((x\ \mathbin{|} (x-1)) + 1)\ \mathbin{\&}\ x) & \text{, or}\\
((x\ \mathbin{\&}\ \mathord{-}\!x) + x)\ \mathbin{\&}\ x
\end{array}
```

These can be used to determine if a nonnegative integer is of the form $`2^j - 2^k`$ for some $`j \geq k \geq 0`$ : apply the formula followed by a 0-test on the result.

*Demo:* [basics_12.c](/Ch02/basics_12.c)

---

### A Novel Application

An application of this sort of bit twiddling is the problem of finding the next higher number after a given number that has the same number of 1-bits. You might very well wonder why anyone would want to compute that. It has applications where bit strings are used to represent subsets. The possible members of a set are listed in a linear array, and a subset is represented by a word or sequence of words in which bit $`i`$ is on if member $`i`$ is in the subset. Set unions are computed by logical $`or`$ of the bit strings, intersections by $`and`$'s, and so on.

You might want to iterate through all the subsets of a given size. This is easily done if you have a function that maps a given subset to the next higher number (interpreting the subset string as an integer) with the same number of 1-bits.

A concise algorithm for this operation was devised by R. W. Gosper. Given a word $`x`$ that represents a subset, the idea is to find the rightmost contiguous group of 1's in $`x`$ and the following 0, and “increment” that quantity to the next value that has the same number of 1's. For example, the string xxx0 1111 0000, where xxx represents arbitrary bits, becomes xxx1 0000 0111.

The algorithm first identifies the "smallest" 1-bit in $`x`$, with $`s = x\ \&\ \!-x`$, giving 0000 0001 0000. This is added to $`x`$, giving $`r`$ = xxx1 0000 0000. The 1-bit here is one bit of the result. For the other bits, we need to produce a right-adjusted string of $`n - 1`$ 1's where $`n`$ is the size of the rightmost group of 1's in $`x`$. This can be done by first forming the *exclusive or* of $`r`$ and $`x`$, which gives 0001 1111 0000 in our example.

This has two too many 1's and needs to be right-adjusted. This can be accomplished by dividing it by $`s`$, which right-adjusts it ($`s`$ is a power of 2), and shifting it right two more positions to discard the two unwanted bits. The final resut is the *or* of this and $`r`$.

In computer algebra notation, the result is $`y`$ in

```math
\begin{aligned}
\ s &\gets x\ \mathbin{\&} \mathord{-}\!x \\
r &\gets s + x \\
y &\gets r \mathbin{|} (((x \oplus r) \stackrel{u}{\gg} 2)\stackrel{u}{\div}s)
\end{aligned}
```

*Demo:* [basics_13.c](/Ch02/basics_13.c)

---

## 2-2 Addition Combined with Logical Operations

## 2-3 Inequalities among Logical and Arithmetic Expressions

## 2-4 Absolute Vaue Function

If your machine does not have an instruction for computing the absolute value, this computation can usually be done in three or four branch-free instructions.

First, compute $`y \gets x \stackrel{s}{\gg} 31`$, and then one of the following:

```math
\begin{array}{c}
\text{abs} \\
(x \oplus y) -y \\
(x+y) \oplus y \\
x - (2x\ \&\ y) \\
\\
\end{array}
```

```math
\begin{array}{c}
\text{nabs} \\
y - (x \oplus y) \\
(y - x) \oplus y \\
(2x\ \&\ y) - x
\end{array}
```

By "$`2x`$" we mean, of course, $`x + x`$ or $`x \ll 1`$.

If you have fast multiplication by variable whose values is $`\pm`$ 1, the following will do:

```math
((x \stackrel{s}{\gg} 30)\ \mathbin{|}\ 1) * x
```

*Demo:* [basics_14.c](/Ch02/basics_14.c)

---

## 2-5 Average of Two Integers

The following formula can be used to compute the average of two unsigned integers $`\lfloor(x + y)/2\rfloor`$, without causing overflow:

```math
(x\ \&\ y) + ((x\ \oplus\ y) \stackrel{u}{\gg}\ 1)
```

The formula below computes $`\lfloor(x + y)/2\rfloor`$ for unsigned integers:

```math
(x\ |\ y) - ((x\ \oplus\ y) \stackrel{u}{\gg}\ 1)
```

To compute the same quantities ("floor and ceiling averages") for signed integers, use the same formulas, but with the unsigned shift replaced with a signed shift.

For signed integers, one might also want the average with the division by 2 rounded toward 0. Computing this "truncated average" (without causing overflow) is a little more difficult. It can be done by computing the floor average and then correcting it. The correction is to add 1 if, arithmetically, $`x + y`$ is negative and odd. But $`x + y`$ is negative if and only if the result of (3), with the unsigned shift replaced with a signed shift, is negative, This leads to the following method (seven instructions on the basic RISC, after commoning the subexpression $`x\ \oplus y`$):

```math
\begin{aligned}
\ t &\gets (x\ \&\ y) + ((x\ \oplus\ y)\ \stackrel{s}{\gg}1); \\
t &+ ((t \stackrel{u}{\gg}31)\ \&\ (x\ \oplus\ y)) \\
\end{aligned}
```

Some common special cases can be done more efficiently. If $`x`$ and $`y`$ are signed integers and known to be nonnegative, then the average can be computed as simply $`(x + y)\ \stackrel{u}{\gg}1`$. The sum can overflow, but the overflow bit is retained in the register that holds the sum, so that the unsigned shift moves the overflow bit to the proper position and supplies a zero sign bit.

If $`x`$ and $`y`$ are unsigned integers and $`x \stackrel{u}{\leq}\ y`$, or if $`x`$ and $`y`$ are signed integers and $`x \leq y`$ (signed comparation), then the average is given by $`x + ((y - x) \stackrel{u}{\gg} 1)`$. These are floor averages, for example, the average of -1 and 0 is -1.

*Demo:* [basics_15.c](/Ch02/basics_15.c)

---

## 2-6 Sign Extension

By "sign extension," we mean to consider a certain bit position in a word to be the sign bit, and we wish to propagate that to the left, ignoring any other bits present.

The standards way to do this is with *shift left logical* followed by *shift right signed*. However, if these instructions are slow or nonexistent on your machine, it can be done wth one of the following, where we illustrate by propagating bit position 7 to the left:

```math
\begin{array}{c}
((x + \text{0x00000080})\ \&\ \text{0x000000FF})\ -\ \text{0x00000080} \\
((x\ \&\ \text{0x000000FF})\ \oplus\ \text{0x00000080})\ -\ \text{0x00000080} \\
(x\ \&\ \text{0x0000007F})\ -\ (x\ \&\ \text{0x00000080})
\end{array}
```

The "+" above can also be "-" or "$`\oplus`$." The second formula is particularly useful if you know that the unwanted high-order bits are all 0's, because then the *and* can be omitted.

*Demo:* [basics_16.c](/Ch02/basics_16.c)

---
