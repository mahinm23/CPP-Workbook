---
title: Unit 1 — Following Commands (C++)
date: 18-06-2026
tags: [cpp, unit1, variables, functions, input]
status: active
---

# Unit 1: Following Commands

## Learning Outcomes
- Read, write programs that read input from the user and store it in a variable
- Read, write programs that print out messages that include the contents of variables
- Read, write programs that are split into functions
- Read, write and use functions that both do and don't return results
- Explain what is meant by a function and a procedure

---

## Core Concept: Variables — Storing Things for Later

A variable is a named box you can put a piece of data in. To use one you must:
1. **Declare** it — tell the compiler to create a box of the right type.
2. **Initialize** it — put something in it.

```cpp
std::string name;        // declare — box exists, but is empty/garbage
name = "fred";           // initialize — "fred" stored in the box
```

When you put something new in a variable, whatever was there before is **destroyed**. When you read a variable, you get a **copy** of its contents — the variable itself is unchanged.

```cpp
std::string name1 = "fred";
std::string name2 = name1;   // copies "fred" into name2 — two independent boxes now
```

---

## C++ Syntax Reference

### Printing
```cpp
#include <iostream>
std::cout << "The message goes here!" << std::endl;
std::cout << "Value: " << x << " and " << y << std::endl;   // mix text and variables
```

### Getting input from the user
Java uses `Scanner`; C++ uses `std::cin` with `<iostream>` (no extra import needed for basic types) and `std::getline` for whole lines of text.

```cpp
#include <iostream>
#include <string>

std::string name;
std::cout << "What's your name?" << std::endl;
std::getline(std::cin, name);   // reads a whole line into name

std::string theyLove;
std::cout << "Who do you love?" << std::endl;
std::getline(std::cin, theyLove);

std::cout << "Oooh! Everyone listen! " << name << " loves " << theyLove << std::endl;
```

For a single number rather than a line of text, `std::cin >> someInt;` works directly — no parsing step needed (contrast with Java's `Integer.parseInt(scanner.nextLine())`).

---

## Functions, Functions and Procedures

- A **function** returns a value you can use later (e.g. on the right of an assignment).
- A **procedure** just does something — no value comes back. In C++ this is a function with return type `void`.

```cpp
// procedure — does something, returns nothing
void printMessage() {
    std::cout << "Hello" << std::endl;
}

// function — returns a value
int add(int a, int b) {
    return a + b;
}
```

### Returning values
The return type goes where Java puts `void`/`String`/`int` in the header line:
```cpp
std::string askName() {
    std::string name;
    std::cout << "What's your name?" << std::endl;
    std::getline(std::cin, name);
    return name;
}
```
Calling a function that returns a value — do something with the result:
```cpp
std::string yourName = askName();
```

---

## Worked Example: keyboard input split into functions

```cpp
#include <iostream>
#include <string>

void askQuestions() {
    std::string name;
    std::string theyLove;

    std::cout << "What's your name?" << std::endl;
    std::getline(std::cin, name);

    std::cout << "Who do you love?" << std::endl;
    std::getline(std::cin, theyLove);

    std::cout << "Oooh! Everyone listen! " << name << " loves " << theyLove << std::endl;
}

int main() {
    askQuestions();
    return 0;
}
```

---

## Exercises

### Exercise 1: Modify the message
Rewrite a function that prints "Hi, there. This is Eddie your shipboard computer" so that instead it prints "Go ahead Punk. Make my day!" without changing the `std::cout` line's structure — just the message and variable name.

### Exercise 2: Rename the variable
Take the function above and rename the variable from `myWelcome` to `happyMessage` everywhere it appears.

### Exercise 3: Address label
Write a program that stores your name, address and postcode in separate variables, then prints them formatted as an address label:
```
Paul Curzon
54 Programming Towers
Shell Street, Java Land
E1 4NS
```

### Exercise 4: Initials in large letters
Write a program that prints your initials in large block letters, using a pattern of characters. Give each initial its own function. Example for initials PC:
```
PPPPPP
P    P
PPPPPP
P
P

CCCCCC
C
C
C
CCCCCC
```

### Exercise 5: Print each letter twice
Extend Exercise 4 so each letter prints twice, by calling each letter's function twice — don't duplicate the printing code itself.

### Exercise 6: String concatenation
Write a program that builds up one message from two pieces using `+`: `"Dave is the best rapper ever."` and `"Blondie is the best rock-pop band ever"`, starting from an empty string and concatenating onto it.

### Exercise 7: Functions calling functions
Write a program with three functions that return answers (not just print them): one asks "Who loves who?" for two names, a third combines the two answers and prints something like: `Jim loves Jo but Sam loves Jim.`

### Exercise 8: Country of birth
Write one function that asks for the country someone was born in, another that asks for their favourite city in that country, and a third that calls both and prints e.g. `Krakow is the nicest city in Poland.`

### Exercise 9: Understanding bugs (debugging practice)
Take your hello-world program from Unit 0 and introduce one error at a time — recompile after each, note the error message and what it means, then fix it before introducing the next:
- a) Delete one of the semicolons.
- b) Change the word `main` to `man`.
- c) Delete a single line.
- d) Remove the quotation marks around a string.

---

## Exam Style Question

**Question 1 [10 marks]**
Explain what the following program fragment does, both line by line and overall:
```cpp
std::string name;
std::cout << "What is your name?" << std::endl;
std::getline(std::cin, name);
std::string response = "Hello " + name;
std::cout << response << std::endl;
```

**Question 2 [10 marks]**
The following fragments contain bugs. Identify and correct them, justifying your corrections.
```cpp
i)   std::string hello1 = "Hello " + "There;
ii)  std::string hello2 = "Hello" + "There";
iii) strng hello3 = "Hello There";
iv)  std::string hello4 = "Hello There"
v)   std::string hello5 = Hello There;
```

**Question 3 [10 marks]**
Write a C++ program that asks the user what colour eyes they have, then prints a message confirming it, e.g.:
```
What colour are your eyes? blue
So your eyes are blue are they. I like blue.
```
