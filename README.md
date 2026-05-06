# pipex

A 42 school project that reimplements the Unix shell pipe mechanism in C.  
`pipex` reproduces the behavior of the shell construct:

```sh
< file1 cmd1 | cmd2 > file2
```

---

## Table of Contents

- [Overview](#overview)
- [How It Works](#how-it-works)
- [Project Structure](#project-structure)
- [Data Structures](#data-structures)
- [Usage](#usage)
- [Building](#building)
- [Error Handling](#error-handling)
- [Key Concepts](#key-concepts)

---

## Overview

`pipex` takes four arguments and connects two shell commands through a Unix pipe, redirecting input from a file and output to another file — exactly as a shell would with the `|` operator.

```
./pipex file1 cmd1 cmd2 file2
```

This is equivalent to:

```sh
< file1 cmd1 | cmd2 > file2
```

- `file1` — input file (read by `cmd1`)
- `cmd1` — first command (reads from `file1`, writes to the pipe)
- `cmd2` — second command (reads from the pipe, writes to `file2`)
- `file2` — output file (written by `cmd2`, created or truncated)

---

## How It Works

The program follows these steps at a high level:

1. **Input validation** — Ensures exactly 4 arguments are provided. Prints usage and exits otherwise.
2. **Data initialisation** — All file descriptors and pointers in the main data structure are set to safe sentinel values (`-1` / `NULL`).
3. **Pipe creation** — A single anonymous pipe (`pipe()`) is created; its read and write ends are stored in the `t_data` struct.
4. **Child setup** — For each of the two commands:
   - The command string is split into an argument vector usable by `execve`.
   - The executable's absolute path is resolved by searching every directory listed in the `PATH` environment variable.
   - The appropriate file is opened (`O_RDONLY` for `file1`, `O_CREAT | O_WRONLY | O_TRUNC` for `file2`).
5. **First child process** (`fork`):
   - `stdin` is replaced with the `file1` file descriptor via `dup2`.
   - `stdout` is replaced with the **write end** of the pipe via `dup2`.
   - Both original pipe file descriptors are closed.
   - `cmd1` is launched with `execve`.
6. **Second child process** (`fork`):
   - `stdin` is replaced with the **read end** of the pipe via `dup2`.
   - `stdout` is replaced with the `file2` file descriptor via `dup2`.
   - Remaining pipe file descriptors are closed.
   - `cmd2` is launched with `execve`.
7. **Parent process cleanup** — The parent closes all open file descriptors, frees all allocated memory, and waits for both children to finish with `waitpid`.

---

## Project Structure

```
42-pipex/
├── include/
│   └── pipex.h                  # All type definitions and function declarations
├── src/
│   ├── pipex.c                  # Entry point (main)
│   ├── input_check/
│   │   └── input_validation.c   # Argument count validation
│   ├── setup_struct/
│   │   ├── setup_struct.c       # Top-level struct initialisation
│   │   ├── initialize_data.c    # Set all fields to safe initial values
│   │   ├── set_pipe_fds.c       # Create the pipe and store its FDs
│   │   ├── setup_children.c     # Set up first_child and second_child structs
│   │   ├── get_all_paths.c      # Extract PATH directories from envp
│   │   ├── get_resolved_path.c  # Resolve a command name to its full path
│   │   └── get_file_fd.c        # Open input / output files
│   ├── child_handeling/
│   │   ├── fork_save.c          # Safe fork() wrapper
│   │   ├── first_child.c        # First child I/O redirection + execve
│   │   └── second_child.c       # Second child I/O redirection + execve
│   ├── error_handling/
│   │   └── exit_clean.c         # Print error, clean up, and exit
│   └── cleanup/
│       └── clean_data.c         # Close FDs and free all heap memory
├── libs/                        # Custom C library (git submodule)
├── Makefile
└── compile_commands.json
```

---

## Data Structures

### `t_child`
Holds everything needed to run one child process.

| Field           | Type      | Description                                      |
|-----------------|-----------|--------------------------------------------------|
| `execve_argv`   | `char **` | NULL-terminated argument vector for `execve`     |
| `path`          | `char *`  | Absolute path to the executable                  |
| `input_file_fd` | `int`     | File descriptor for the child's input file       |
| `output_file_fd`| `int`     | File descriptor for the child's output file      |

### `t_data`
The global state passed through the entire program.

| Field          | Type       | Description                                    |
|----------------|------------|------------------------------------------------|
| `first_child`  | `t_child`  | State for the first command                    |
| `second_child` | `t_child`  | State for the second command                   |
| `pipe_fds[2]`  | `int[2]`   | Pipe read (`[0]`) and write (`[1]`) ends       |
| `child_pids[2]`| `pid_t[2]` | PIDs of the two child processes                |
| `envp`         | `char **`  | Pointer to the environment variable array      |

### `t_path_sizes`
A helper struct used only during path resolution to avoid multiple `strlen` calls.

---

## Usage

### Basic example

```sh
./pipex infile "ls -l" "grep pipex" outfile
```

Equivalent shell command:

```sh
< infile ls -l | grep pipex > outfile
```

### Another example

```sh
./pipex /etc/passwd "cat" "wc -l" result.txt
```

Equivalent shell command:

```sh
< /etc/passwd cat | wc -l > result.txt
```

### Invalid usage

If the wrong number of arguments is provided, the program prints:

```
Invalid input, correct usage: ./pipex file1 cmd1 cmd2 file2
```

and exits with code `1`.

---

## Building

The project uses a standard 42-style Makefile.

```sh
# Build the executable
make

# Remove object files
make clean

# Remove object files and the executable
make fclean

# Full rebuild
make re
```

The Makefile also automatically initialises and builds the `libs` git submodule (a custom C library equivalent to `libft`) when needed.

**Compiler flags:** `-Wall -Werror -Wextra`

---

## Error Handling

All errors go through a single `exit_clean` function:

```c
void exit_clean(t_data *data, char *error, int error_code);
```

It calls `perror` with the provided error string (typically `__FILE__` for context), runs `clean_data` to free all resources, and calls `exit` with the given code. This guarantees no file descriptors are leaked and no heap memory goes unfreed on abnormal termination.

`clean_data` safely handles partially-initialised state by checking for sentinel values (`-1` / `NULL`) before closing or freeing anything.

---

## Key Concepts

| Concept | System calls / functions used |
|---------|-------------------------------|
| Inter-process communication | `pipe(2)` |
| Process creation | `fork(2)` |
| I/O redirection | `dup2(2)`, `close(2)` |
| Command execution | `execve(2)` |
| PATH resolution | `access(2)`, `ft_split`, `ft_strncmp` |
| File I/O | `open(2)` with `O_RDONLY`, `O_CREAT`, `O_WRONLY`, `O_TRUNC` |
| Process synchronisation | `waitpid(2)` |
| Memory management | `malloc` / `free` via custom `libft` wrappers |

---

## Author

**Fritz Gabler** — 42 student (`fgabler`)
