Shell Program
This is a simple shell program written in C. It provides a basic command-line interface for executing commands.

Usage

Compilation:
Compile the program using a C compiler.

Execution:
Run the compiled executable.

Shell Commands:
The shell supports basic commands entered through the command line.
Commands can include spaces and various tokens.

Features

Command Execution:
The program reads commands from the user and executes them.
It uses fork() and execvp() to create a child process for command execution.

Path Resolution:
The execute_command function attempts to resolve the full path of the command.
It checks the given command against the system's PATH variable and executes it if found.

How to Use

Enter Commands:
Enter commands at the shell prompt.
Commands are executed, and the output is displayed.

Exit the Shell:
To exit the shell, use the appropriate exit command (e.g., Ctrl+C).

Limitations
This shell does not handle complex command structures, pipelines, or redirection.

Contributors
Kamal Huseynli and Zaman Kazimov
