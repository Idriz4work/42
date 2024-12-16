# PIPEX 

## How Does It Work?
`pipex` is a utility that chains commands together using Unix pipes, allowing the output of one command to serve as the input for the next. Here’s how the basic functionality works:

1. **Read Input from `file1`**: The content of `file1` is read.
2. **Execute `cmd1`**: The first command (`cmd1`) is executed on the content of `file1`.
3. **Pipe to `cmd2`**: The output of `cmd1` is passed as input to the second command (`cmd2`) using a pipe.
4. **Write to `file2`**: The output of `cmd2` is written to `file2`.

### Basic Workflow Example:
- opens file1, does the cmd1 on the file1, creates a pipe which then sends the output of the cmd1 to the input of cmd2. Output of cmd2 gets written to file2 
1. file1 <== read & do cmd1 
2. output of cmd1 ==> input of cmd2
3. file2 <== write output of cmd2

---

## How Does the Bonus Work?
The bonus functionality extends `pipex` by handling:

### 1. **Multiple Pipes**
`pipex` can now chain multiple commands together, creating intermediate pipes between each command:

1. **Read Input from `file1`**: The content of `file1` is read.
2. **Execute `cmd1`**: The first command (`cmd1`) processes the input from `file1`.
3. **Pipe Between Commands**: The output of `cmd1` is passed as input to `cmd2`.
4. **Continue Through Additional Commands**: This process repeats for each subsequent command (`cmd3`, `cmd4`, etc.).
5. **Write to `file2`**: The output of the last command is written to `file2`.

### Basic Workflow Example:
1. file1 <== read & do cmd1 
2. output of cmd1 ==> input of cmd2
3. output of cmd2 ==> input of cmd3 
4. output of cmd3 ==> input of cmd4
5. file2 <== write output of cmd4

---

### 2. **Support for "here_doc"**
When the first parameter is `here_doc`, `pipex` simulates the behavior of shell redirections `<<` (here-document) and `>>` (append output):

1. **Check for "here_doc"**: If the second argument is `"here_doc"`, the input is treated as a here-document.
2. **Process Commands**: Commands are executed as in the multiple pipes workflow, where:
   - `<<` reads input until a delimiter is encountered.
   - `>>` appends the output to the specified file.
3. **Write to `file2`**: The final output is written to `file2`, appending if `>>` is specified.

### Example Workflow for "here_doc":
1. **Input**: `<< delimiter` is used to feed input into the command chain.
2. **Chaining Commands**: Output from each command is piped into the next.
3. **Output**: The final result is appended to `file2` using `>>`.

---

### Summary
`pipex` is a versatile utility that simplifies chaining of commands with file input and output redirection. The bonus functionality extends its capabilities, allowing for multi-step command chains and support for advanced redirection using `here_doc`.
