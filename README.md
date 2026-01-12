Simple Shell (hsh)
===================

Description
-----------
This repository implements a small Unix-like command interpreter (simple shell) written in C. The shell reads lines from standard input, tokenizes them on spaces, and executes commands either by resolving them via the `PATH` environment variable or by executing an absolute/relative path directly.

Key behaviors (confirmed from source)
- Prompt: the interactive prompt printed is `@zerobors$ ` (from `main.c`).
- Tokenization: input is split using `strtok(line, " ")`.
- Builtins: the shell supports the following builtins as implemented in `builtins.c`:
	- `exit` — exits the shell (implemented by `_hsexit`).
	- `env` — prints all environment variables.
	- `unsetenv` — removes an environment variable.
- PATH resolution: `path_finder` (in `paths.c`) reads the `PATH` environment variable and searches each directory for the requested command, using `access(..., X_OK)` to check executability.
- Execution: `_exec` (in `exec.c`) forks and calls `execve(path, argv, environ)` in the child; the parent waits and updates the global `status`.
- Direct execution: `accessable` (in `access.c`) uses `access(cmd, X_OK)` and calls `_exec` for absolute/relative paths.
- Environment helpers: `_getenv` and `_varcmp` (in `getenv.c` and `strings.c`) locate environment variables in `environ`.
- Error reporting: `_peror` (in `error.c`) writes structured error messages to `stderr` and sets `status = 127`.

Files
-----
- `main.c` — program entry, prompt loop, input reading and tokenization.
- `exec.c` — fork/exec wrapper (`_exec`).
- `paths.c` — PATH parsing and command lookup (`path_finder`).
- `access.c` — checks/accesses direct command paths (`accessable`).
- `builtins.c` — builtin command implementations (`exit`, `env`, `unsetenv`).
- `getenv.c` — environment variable lookup helpers (`_getenv`).
- `strings.c` — small string helper functions (`_strlen`, `_strcpy`, `_strcmp`, `_strcat`, `_varcmp`).
- `error.c` — error formatting and printing (`_peror`).
- `shell.h` — project header with prototypes and shared globals.
- `hsh` — present in the repository (likely the compiled binary or a helper); see `AUTHORS` for authorship notes.

Build
-----
This project contains plain C source files. You can compile the shell with `gcc` using all `.c` files. One example command that compiles the sources into an executable named `hsh`:

```sh
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

Running
-------
- Interactive: run `./hsh` to start the prompt `@zerobors$ ` and enter commands.
- Non-interactive: the shell reads from `stdin` so it can be used with input redirection or piping.

Notes and limitations (explicitly from code)
- Tokenization splits only on spaces (`" "`), so quoted arguments are not specially handled.
- Builtins are limited to `exit`, `env`, and `unsetenv` as implemented.
- PATH parsing assumes the `PATH` environment variable exists; if not found, `path_finder` returns without executing a command.
- The shell uses `getline` and `strtok` from the standard library.

Authors
-------
See the repository `AUTHORS` file for contributor information.

