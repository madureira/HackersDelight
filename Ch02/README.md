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
