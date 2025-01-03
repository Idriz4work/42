# 📖 Pipex

Pipex is a project that re-creates the shell pipe functionality (`|`) in C. It simulates piping by allowing the output of one command to be passed as input to another, using system calls like `pipe()`, `fork()`, `dup2()`, and `execve()`.

## Table of Contents
- [Clone](#Clone-repository)
- [Usage](#usage)
- [How It Works](#how-it-works)
  - [Core System Calls](#core-system-calls)
  - [Process Flow](#process-flow)
- [Implementation Steps](#implementation-steps)
  - [1. Setting Up the Pipe](#1-setting-up-the-pipe)
  - [2. Forking the Processes](#2-forking-the-processes)
  - [3. Redirecting FDs with dup2()](#3-redirecting-fds-with-dup2)
  - [4. Executing Commands with execve()](#4-executing-commands-with-execve)
- [Debugging Tips](#debugging-tips)
- [License](#license)

## Clone repository
```bash
git clone https://github.com/Idriz4work/42/tree/main/pipex
```

## Usage

### Compilation
```bash
gcc -Wall -Werror -Wextra -o pipex pipex.c
```

### Running the Program
```bash
./pipex infile "cmd1 args" "cmd2 args" outfile
```

### Example
```bash
./pipex input.txt "grep keyword" "wc -l" output.txt
```

- `infile`: File whose content serves as input for cmd1
- `cmd1`: The first command to execute
- `cmd2`: The second command to execute
- `outfile`: File where cmd2's output is written

## How It Works

### Core System Calls
- `pipe()`: Creates a communication channel with two ends:
  - `end[0]`: Read end
  - `end[1]`: Write end
- `fork()`: Splits the process into parent and child processes that run concurrently
- `dup2()`: Redirects file descriptors (e.g., makes a file or pipe endpoint the standard input/output)
- `execve()`: Replaces the current process with a new program

### Process Flow
1. Child Process (cmd1):
   - Redirects infile to stdin
   - Redirects end[1] (pipe's write end) to stdout
   - Executes cmd1

2. Parent Process (cmd2):
   - Waits for the child to finish
   - Redirects end[0] (pipe's read end) to stdin
   - Redirects outfile to stdout
   - Executes cmd2

## Implementation Steps

### 1. Setting Up the Pipe
Create a pipe to establish a communication channel:
```c
int end[2];
pipe(end);
```
- `end[0]`: Read end of the pipe
- `end[1]`: Write end of the pipe

### 2. Forking the Processes
Fork the process to create a parent-child relationship:
```c
pid_t pid = fork();
if (pid < 0) {
    perror("Fork error");
    exit(EXIT_FAILURE);
}
```
- Child Process (`pid == 0`): Executes the first command
- Parent Process (`pid > 0`): Executes the second command after waiting for the child to finish

### 3. Redirecting FDs with `dup2()`
Use `dup2()` to redirect input/output for commands:
```c
dup2(input_fd, STDIN_FILENO);  // Redirect input
dup2(output_fd, STDOUT_FILENO); // Redirect output
close(unused_fd);
```

Child Process:
- Redirect infile to stdin
- Redirect end[1] to stdout

Parent Process:
- Redirect end[0] to stdin
- Redirect outfile to stdout

### 4. Executing Commands with `execve()`
Use `execve()` to replace the current process with the desired command:
```c
execve(cmd_path, cmd_args, envp);
```
- `cmd_path`: Path to the command (e.g., /bin/ls)
- `cmd_args`: Array of arguments for the command
- `envp`: Environment variables (used to locate command paths)

If `execve()` fails, handle errors and free resources:
```c
perror("Command execution failed");
exit(EXIT_FAILURE);
```

## Debugging Tips

1. Check Paths:
   - Split the PATH environment variable and append `/` to each path to ensure correct command paths

2. Close Unused Pipe Ends:
   - Always close the pipe ends you do not use
   - Leaving them open can cause processes to hang, waiting for input that never arrives

3. Use `perror()` for Debugging:
   - Place `perror("Error message")` after system calls like `fork()` and `execve()` to diagnose failures

4. Handle File Errors:
   - Use `chmod` to verify file permissions
   - Handle cases where files cannot be opened, read, or written properly

### Example File Descriptor Flow
At runtime, file descriptors are assigned as follows:
```
FD   Description
-----------------
0    stdin
1    stdout
2    stderr
3    infile
4    outfile
5    end[0] (pipe read)
6    end[1] (pipe write)
```

Child Process (cmd1):
- Redirect infile → stdin
- Redirect end[1] → stdout

Parent Process (cmd2):
- Redirect end[0] → stdin
- Redirect outfile → stdout

## License
This project is open-source and available under the MIT License.
