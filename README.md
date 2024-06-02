## Minishell Project

The **minishell** project involves creating a simplified version of a shell, similar to bash, that efficiently handles command execution, redirections, pipes, and signals, while implementing essential built-in commands with the following functionalities:

#### User Interface
- Displays a prompt when waiting for a new command.
- Includes a functional command history.

#### Command Execution
- Searches for and launches the correct executable based on the PATH variable or using a relative or absolute path.

#### Signal Handling
- Avoids using more than one global variable to indicate a received signal, ensuring that the signal handler does not access main data structures.

#### Quotes and Special Characters
- Does not interpret unclosed quotes or unnecessary special characters such as \ (backslash) or ; (semicolon).
- Handles single quotes (') to prevent the shell from interpreting metacharacters in the quoted sequence.
- Handles double quotes (") to prevent the shell from interpreting metacharacters in the quoted sequence except for the $ (dollar sign).

#### Redirections
- `<` redirects input.
- `>` redirects output.
- `<<` (heredoc) reads the input until a line containing a specified delimiter is seen, but does not update the history.
- `>>` redirects output in append mode.

#### Pipes
- Implements the `|` character to connect the output of one command to the input of the next command via a pipe.

#### Environment Variables
- Handles environment variables, expanding to their values when `$` is followed by a sequence of characters.
- Handles `$?`, which expands to the exit status of the most recently executed foreground pipeline.

#### Control Signals in Interactive Mode
- `ctrl-C` displays a new prompt on a new line.
- `ctrl-D` exits the shell.
- `ctrl-\` does nothing.

#### Built-in Commands
- `echo` with the `-n` option.
- `cd` with only a relative or absolute path.
- `pwd` with no options.
- `export` with no options.
- `unset` with no options.
- `env` with no options or arguments.
- `exit` with no options.


![game](https://raw.githubusercontent.com/xilen0x/xilen0x/master/images_x_repos/Screenshot%20from%202024-06-02%2013-26-40.png)