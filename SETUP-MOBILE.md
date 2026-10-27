# Mobile Offline Setup (iPhone)

Desktop is already fully offline (VS Code + local compiler). This covers doing these exercises on iPhone, offline, after a one-time setup that needs internet.

## Is it an IDE?

No - both options below are terminal apps, not IDEs. No GUI project tree, no autocomplete/IntelliSense. You write code in **vim** or **emacs** (both bundled), with basic syntax highlighting (`:syntax on` in vim) and nothing beyond that - matching the `.vscode` settings in this repo, which already disable autocomplete so exercises get typed from memory.

## Option 1: a-Shell (recommended)

Native iOS terminal app - no x86 emulation, so it's fast. Comes with `clang`, `vim`, `pico` pre-installed, no package manager step needed. **Correction (17-10-2026):** a-Shell does NOT include real `git` - it ships `lg2`, a lightweight git-equivalent built on libgit2, which mirrors git's subcommands (clone/add/commit/push) but isn't a 1:1 match. Verified live against the actual app, not assumed.

1. Install **a-Shell** from the App Store (free) - not "a-Shell mini", which strips out some bundled tools.
2. Clone this repo (needs internet, one-time):
   ```
   lg2 clone https://github.com/mahinm23/CPP-Workbook.git
   cd CPP-Workbook
   ```
3. Read the exercise guide (`less "Intermediate/OOP/Ex3/03_encapsulation.md"`), then create/edit your own file: `vim "Intermediate/OOP/Ex3/03_encapsulation.cpp"` (quote paths with spaces).
4. Compile and run, fully offline from here on:
   ```
   clang++ "Intermediate/OOP/Ex3/03_encapsulation.cpp" -o out && ./out
   ```
5. Sync back to desktop (needs internet again):
   ```
   lg2 add -A
   lg2 commit -m "..."
   lg2 push
   ```
   GitHub no longer accepts a plain password over HTTPS for push - if prompted for one, use a Personal Access Token instead (github.com > Settings > Developer settings > Personal access tokens). Not yet independently confirmed against the real app - `lg2 clone` was given as the fix for the `git: command not found` error but not yet reported back as working; add/commit/push syntax is a best guess based on `lg2` mirroring git's subcommands. If any flags differ, `lg2 <subcommand> --help` shows the real ones - update this doc once confirmed.

## Option 2: iSH (fallback)

Full Alpine Linux, x86-emulated (slower than a-Shell). Use only if a-Shell's narrower toolset is ever insufficient.

1. Install **iSH** from the App Store (free).
2. One-time package install (needs internet):
   ```
   apk add clang git vim
   ```
3. Same clone/edit/compile/push workflow as a-Shell above.

## Minimal vim cheat sheet

Vim has a huge command set, but this workflow only needs this much of it:

| Action | Command |
|---|---|
| Open a file | `vim filename.cpp` |
| Start typing | `i` (enters insert mode) |
| Stop typing / back to commands | `Esc` |
| Save and quit | `:wq` then Enter |
| Quit without saving | `:q!` then Enter |
| Move cursor | arrow keys, or `h j k l` = left/down/up/right |
| Undo | `u` |
| Delete a line | `dd` |
| Turn on colour highlighting | `:syntax on` |

The one thing that trips people up: you can't type immediately when vim opens - press `i` first, and press `Esc` before any `:` command (including saving). Everything else is optional for this.

## Notes

- Both apps expose their filesystem to the iOS Files app, so a GUI text editor with Files integration (e.g. Textastic) could replace vim for editing if the terminal-only workflow proves too awkward on a phone keyboard - not set up yet, only worth doing if vim itself becomes the blocker.
- `answers/` folders in each exercise set follow the usual convention: write your own attempt in the exercise file first, check the matching file under `answers/` after. See the vault's `Learning/cpp/cpp-tracker.md` for the full reasoning.
