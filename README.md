# Hacker's Delight

Implementations from the book "Hacker's Delight" 2nd Edition by Henry S. Warren, Jr.

## About the book

> In _**Hacker’s Delight, Second Edition**_, Hank Warren once again compiles an irresistible collection of programming hacks: timesaving techniques, algorithms, and tricks that help programmers build more elegant and efficient software, while also gaining deeper insights into their craft.
> Warren’s hacks are eminently practical, but they’re also intrinsically interesting, and sometimes unexpected, much like the solution to a great puzzle. They are, in a word, a delight to any programmer who is excited by the opportunity to improve.

<p align="center">
    <img src=".github/book_cover.jpg?raw=true"/>
</p>

:blue_book: [Amazon.com](https://a.co/d/bBxyiJj)

### Running an example

Use the `run.sh` script from the project root, passing the folder and file name without extension:

```bash
./run.sh Ch02/basics_01.c
```

### Cleaning compiled binaries

Use `clean.sh` to remove all compiled binaries. It defaults to the project root, or accepts a specific chapter folder:

```bash
# Clean everything
./clean.sh

# Clean a specific chapter
./clean.sh Ch02
```
