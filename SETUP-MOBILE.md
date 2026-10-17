# Mobile Offline Setup (iPhone)

Desktop is already fully offline (VS Code + local compiler). This covers doing these exercises on iPhone, offline, after a one-time setup that needs internet.

## Is it an IDE?

No - both options below are terminal apps, not IDEs. No GUI project tree, no autocomplete/IntelliSense. You write code in **vim** or **emacs** (both bundled), with basic syntax highlighting (`:syntax on` in vim) and nothing beyond that - matching the `.vscode` settings in this repo, which already disable autocomplete so exercises get typed from memory.

## Option 1: a-Shell (recommended)

Native iOS terminal app - no x86 emulation, so it's fast. Comes with `clang`, `git`, `vim`, `emacs` pre-installed, no package manager step needed.

1. Install **a-Shell** from the App Store (free).
2. Clone this repo (needs internet, one-time):
   ```
   git clone https://github.com/mahinm23/CPP-Workbook.git
   cd CPP-Workbook
   ```
3. Edit a file: `vim "Intermediate/OOP/03_rule_of_three_five.cpp"` (quote paths with spaces).
4. Compile and run, fully offline from here on:
   ```
   clang++ "Intermediate/OOP/03_rule_of_three_five.cpp" -o out && ./out
   ```
5. Sync back to desktop: `git add -A && git commit -m "..." && git push` (needs internet again, same as any git push).

## Option 2: iSH (fallback)

Full Alpine Linux, x86-emulated (slower than a-Shell). Use only if a-Shell's narrower toolset is ever insufficient.

1. Install **iSH** from the App Store (free).
2. One-time package install (needs internet):
   ```
   apk add clang git vim
   ```
3. Same clone/edit/compile/push workflow as a-Shell above.

## Notes

- Both apps expose their filesystem to the iOS Files app, so a GUI text editor with Files integration (e.g. Textastic) could replace vim for editing if the terminal-only workflow proves too awkward on a phone keyboard - not set up yet, only worth doing if vim itself becomes the blocker.
- `answers/` folders in each exercise set follow the usual convention: write your own attempt in the exercise file first, check the matching file under `answers/` after. See the vault's `Learning/cpp/cpp-tracker.md` for the full reasoning.
