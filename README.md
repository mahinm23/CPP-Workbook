# CPP-Workbook

ECS401 C++ workbook exercises, plus supplementary OOP and STL exercise sets, done as part of the quant-dev C++ learning path. Progress tracked in the second-brain vault: `Learning/cpp/cpp-tracker.md`.

## Desktop setup (macOS)

Compiler is Xcode Command Line Tools' `clang++`/`g++` - already installed. Check with:
```
clang++ --version
```
If missing (fresh machine): `xcode-select --install`.

Editor is VS Code. `.vscode/settings.json` disables autocomplete/IntelliSense on purpose - exercises are typed from memory, not copied.

## Compiling and running a file

```
clang++ "path/to/file.cpp" -o out && ./out
```
Quote the path if it contains spaces (most workbook folders do, e.g. `"0) Getting Started"`).

## Mobile / offline setup

Doing these exercises on iPhone (a-Shell or iSH, no desktop needed): see [SETUP-MOBILE.md](SETUP-MOBILE.md).

## Exercise convention

Same as the ECS401 units (`Workbook Guides/*.md`): instructions live in Markdown, code you write lives in `.cpp`. Each Intermediate exercise has a guide (`Intermediate/OOP/*.md`, `Intermediate/STL/*.md`) with the concept, the exercise spec, and the headers needed - create your own `.cpp` with the same name next to it and attempt it fresh from memory. A reference solution for each lives in the matching `answers/` subfolder - check it only after attempting, not before.
