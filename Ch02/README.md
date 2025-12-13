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
\neg (x\ \mathbin{|} \mathord{-}\!x)   & \text{, or}\\
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
