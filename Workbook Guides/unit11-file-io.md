---
title: Unit 11 — File I/O & Characters (C++)
date: 18-06-2026
tags: [cpp, unit11, file-io, characters]
status: active
---

# Unit 11: File I/O & Characters

## Learning Outcomes
- Open, write to, and read from text files in C++
- Read file contents line by line to end of file
- Write programs using character-level operations
- Understand ASCII character encoding

---

## C++ Syntax Reference

### File I/O headers
```cpp
#include <fstream>    // ofstream (write), ifstream (read)
#include <string>     // std::string, std::getline
#include <iostream>   // std::cout, std::cin
```

### Writing to a file (ofstream)
```cpp
std::ofstream outFile;
outFile.open("wombat.txt");         // creates or overwrites file

outFile << "Hello, World!" << std::endl;
outFile << "Second line" << std::endl;

outFile.close();                    // always close when done
```

### Appending to a file (don't overwrite)
```cpp
std::ofstream outFile;
outFile.open("log.txt", std::ios::app);  // append mode
outFile << "New entry" << std::endl;
outFile.close();
```

### Reading from a file (ifstream), line by line
```cpp
std::ifstream inFile;
inFile.open("wombat.txt");

std::string line;
while (std::getline(inFile, line)) {
    std::cout << line << std::endl;
}

inFile.close();
```

The `while (std::getline(...))` loop:
- Reads one line at a time into `line`
- Returns false at end of file (EOF)
- Strips the newline character from `line`

### Check if file opened successfully
```cpp
std::ifstream inFile;
inFile.open("data.txt");
if (!inFile) {
    std::cout << "Could not open file." << std::endl;
    return 1;
}
```

### Reading user-supplied filename
```cpp
std::string filename;
std::cout << "Enter filename: ";
std::getline(std::cin, filename);

std::ofstream outFile;
outFile.open(filename);
```

---

## Characters and ASCII

### char type
```cpp
char c = 'A';          // single character, single quotes
std::cout << c << std::endl;     // prints: A
std::cout << (int)c << std::endl;  // prints: 65 (ASCII value)
```

### ASCII table (key values)
```
'0'–'9'   →  48–57
'A'–'Z'   →  65–90
'a'–'z'   →  97–122
' '       →  32
'\n'      →  10
```

### char arithmetic
```cpp
char c = 'a';
std::cout << (char)(c + 1) << std::endl;  // prints: b
std::cout << (char)('A' + 25) << std::endl;  // prints: Z

// Check if digit
bool isDigit = (c >= '0' && c <= '9');

// Convert lowercase to uppercase
if (c >= 'a' && c <= 'z') {
    char upper = c - 32;    // 'a' is 97, 'A' is 65, diff = 32
}
```

### Reading single characters
```cpp
char ch;
std::cin >> ch;          // reads next non-whitespace char
std::cin.get(ch);        // reads exactly one char (including spaces)
```

### Iterating over a string character by character
```cpp
std::string word = "hello";
for (int i = 0; i < word.length(); i++) {
    std::cout << word[i] << std::endl;  // each char
}
// Or:
for (char c : word) {
    std::cout << c << std::endl;
}
```

---

## Worked Example 1: Write name/address to file

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile;
    outFile.open("wombat.txt");

    outFile << "Mahin Mostafa" << std::endl;
    outFile << "123 Example Road" << std::endl;
    outFile << "London, E1 1AB" << std::endl;

    outFile.close();
    std::cout << "Written to wombat.txt" << std::endl;
    return 0;
}
```

---

## Worked Example 2: Display file with line numbers

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile;
    inFile.open("wombat.txt");

    if (!inFile) {
        std::cout << "Could not open file." << std::endl;
        return 1;
    }

    std::string line;
    int lineNum = 1;

    while (std::getline(inFile, line)) {
        std::cout << lineNum << ": " << line << std::endl;
        lineNum++;
    }

    inFile.close();
    return 0;
}
```

---

## Worked Example 3: Copy file

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile;
    std::ofstream outFile;
    inFile.open("input.txt");
    outFile.open("output.txt");

    std::string line;
    while (std::getline(inFile, line)) {
        outFile << line << std::endl;
    }

    inFile.close();
    outFile.close();
    std::cout << "Copy complete." << std::endl;
    return 0;
}
```

---

## Worked Example 4: Word count (like `wc`)

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile;
    inFile.open("input.txt");

    if (!inFile) {
        std::cout << "Could not open file." << std::endl;
        return 1;
    }

    int lines = 0, words = 0, chars = 0;
    std::string line;

    while (std::getline(inFile, line)) {
        lines++;
        chars += line.length();

        bool inWord = false;
        for (int i = 0; i < line.length(); i++) {
            if (line[i] != ' ' && !inWord) {
                inWord = true;
                words++;
            } else if (line[i] == ' ') {
                inWord = false;
            }
        }
    }

    inFile.close();
    std::cout << "Lines: " << lines << std::endl;
    std::cout << "Words: " << words << std::endl;
    std::cout << "Chars: " << chars << std::endl;
    return 0;
}
```

---

## Exercises

### Exercise 1: Write name and address
Write a program that writes your name and address to `wombat.txt`. Run it, then open the file to verify it worked.

```cpp
// Starter
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ofstream outFile;
    outFile.open("wombat.txt");
    // YOUR CODE — write at least 3 lines to the file
    outFile.close();
    return 0;
}
```

### Exercise 2: Display file with line numbers
Write a program that reads `wombat.txt` (from Exercise 1) and prints each line with its line number:
```
1: Mahin Mostafa
2: 123 Example Road
...
```

### Exercise 3: User-specified filename
Write a program that:
1. Asks the user for a filename
2. Asks the user to type text (press Enter after each line; type "DONE" to stop)
3. Writes each line to the file until the user types "DONE"

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::getline(std::cin, filename);

    std::ofstream outFile;
    outFile.open(filename);

    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == "DONE") break;
        // YOUR CODE — write line to file
    }

    outFile.close();
    return 0;
}
```

### Exercise 4: Write 10 names to file
Write a program that:
1. Loops 10 times
2. Each iteration: reads a name from keyboard
3. Writes all 10 names to `names.txt`, one per line

### Exercise 5: Copy file
Write a program that copies `input.txt` to `output.txt` line by line.
Extension: also print each line to the screen while copying.

### Exercise 6: Remove blank lines
Write a program that:
1. Reads `input.txt` line by line
2. Writes to `output.txt` — but skips any blank lines

```cpp
while (std::getline(inFile, line)) {
    if (line != "") {    // or: if (!line.empty())
        outFile << line << std::endl;
    }
}
```

### Exercise 7: Word count
Write `wc` (see worked example above). Test it against a known file.
Extension: also count sentences (end with `.`, `!`, or `?`).

---

## Bracket Checker (ASCII exercise — harder)

Read a file and check if every `(` has a matching `)`. Use a counter: +1 for `(`, -1 for `)`. If it goes negative or ends non-zero, there's a mismatch.

```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream inFile;
    inFile.open("code.txt");

    int depth = 0;
    char ch;
    while (inFile.get(ch)) {    // reads one char at a time including spaces
        if (ch == '(') depth++;
        if (ch == ')') depth--;
        if (depth < 0) {
            std::cout << "Unmatched ')' found" << std::endl;
            return 0;
        }
    }

    inFile.close();
    if (depth == 0)
        std::cout << "Brackets balanced" << std::endl;
    else
        std::cout << depth << " unclosed '(' found" << std::endl;
    return 0;
}
```

---

## Exam Style Question

**a.** A program needs to read a text file line by line. Write a C++ code fragment that:
- Opens `data.txt` for reading
- Prints each line to the screen with its line number
- Handles the case where the file does not exist
[6 marks]

**b.** Explain what happens to the data in a file when you open it with:
(i) `outFile.open("data.txt")` — the file already exists
(ii) `outFile.open("data.txt", std::ios::app)` — the file already exists
What would you use each for? [9 marks]

**c.** A student writes a program to count all words in a file.
Describe the algorithm you would use, then write it in C++. Justify any assumptions you make about what counts as a word. [10 marks]
