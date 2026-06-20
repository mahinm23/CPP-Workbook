---
title: Unit 0 — Getting Started (C++)
date: 18-06-2026
tags: [cpp, unit0, basics]
status: active
---

# Unit 0: Getting Started

## Learning Outcomes
- Explain what an algorithm is
- Use g++ to compile and run a simple program
- Read, write, compile and run simple C++ programs

---

## Core Concept: Algorithms and Programs

An **algorithm** is a set of precise instructions that, when followed, achieves some task. There are many ways (algorithms) to achieve the same task — a recipe is an algorithm; so is a strategy for noughts and crosses.

A **program** is an algorithm written in a language a computer can follow. The language must be completely unambiguous — it must cover every possibility, unlike human language.

---

## Java vs C++: Program Structure

In Java, *everything* lives inside a `class`, even a one-line program. In C++ you don't need a class wrapper at all for simple procedural programs — just functions and a `main`.

**Java:**
```java
class hello
{
    public static void main (String[] param)
    {
        helloMessage();
        return;
    } // END main

    public static void helloMessage ()
    {
        System.out.println("Hello World!");
        return;
    } // END helloMessage
} // END class hello
```

**C++ equivalent:**
```cpp
#include <iostream>

void helloMessage() {
    std::cout << "Hello World!" << std::endl;
}

int main() {
    helloMessage();
    return 0;
}
```

Notes:
- No enclosing `class` needed.
- `main` returns `int`, not `void` — return `0` to mean "no error".
- `System.out.println(x)` becomes `std::cout << x << std::endl;`
- C++ functions can be defined in any order, but a function must be **declared before it's used**. Since `helloMessage` is defined above `main` here, that's fine. If you want to define it below `main`, add a **forward declaration** (`void helloMessage();`) above `main` first.

---

## Compiling and Running

| Step | Java | C++ |
|------|------|-----|
| Write | `hello.java` | `hello.cpp` |
| Compile | `javac hello.java` | `g++ hello.cpp -o hello` |
| Run | `java hello` | `./hello` |

The compiler checks for **syntax errors** (spelling mistakes, missing punctuation) before producing anything runnable. If there are no mistakes, it converts your source into an executable.

One-liner used throughout this flight:
```bash
g++ -Wall filename.cpp -o out && ./out
```
`-Wall` turns on extra warnings — worth always having on.

---

## Structure: Curly Brackets

Curly brackets `{ }` mark where a block of code (a function, a loop body, an if branch) starts and ends — identical role to Java. Indent consistently inside them; it's the single biggest thing that keeps a program readable.

```cpp
int main() {

}   // matches the opening { right above main
```

---

## Comments

```cpp
// single line comment
/* multi-line
   comment */
```
Comments are ignored by the compiler — they're for humans. Always comment what a block of code does and why, not just what each line literally says.

---

## Exercises

### Exercise 1: Output
Write a program that prints out: `Hello my name is C3PO`

```cpp
#include <iostream>

int main() {
    // YOUR CODE HERE
    return 0;
}
```

### Exercise 2: Understanding compiler errors
Take your working hello-world program and, one at a time, introduce a single error, compile, read the error message, and work out what it means. Fix it before introducing the next:
- a) Delete one of the semicolons.
- b) Change the word `main` to `man`.
- c) Delete a single line.
- d) Remove the quotation marks from around `"Hello World!"`.

Keep a "bug book" — note the error message, what caused it, and the fix. You'll see the same handful of error messages again and again; recognising them fast saves a lot of time.

**Tip:** if there are multiple errors, fix the *first* one and recompile — later ones are often caused by the first.
