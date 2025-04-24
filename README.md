# holbertonschool-simple_shell
# Simple Shell - README

# Description

Simple Shell (hsh) is a basic UNIX command line interpreter written in C. It mimics the core behavior of /bin/sh, allowing users to type commands, execute programs, and use a few built-in commands. The shell operates in both interactive and non-interactive modes, handling user input, parsing commands, and executing them in child processes.

# Basic Workflow

# Start the shell.

Display a prompt and wait for user input.

Parse the input into commands and arguments.

Execute the command (either as a built-in or by searching the PATH).

Return to the prompt and repeat.

Exit when the user types exit or sends an EOF (Ctrl+D).

# Features
Prompt display: Shows a prompt and waits for user input.

Command execution: Runs executable programs, with or without arguments.

Built-in commands: Supports exit (to quit the shell) and env (to print environment variables).

PATH handling: Searches for commands in the directories listed in the PATH environment variable.

Error handling: Prints errors with the shell's executable name as prefix, matching /bin/sh output conventions.

Interactive and non-interactive modes: Works with both direct user input and piped input from files or other programs.

EOF handling: Exits gracefully on Ctrl+D.


# Compilation
Compile the shell using:


# gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh

# File Structure

#File	              # Description
main.c :	    Entry point; main loop for reading and executing commands
main.h :	    Head

# Summary Table 

Summary Table: 

The summary table outlines the purpose, content guidelines, and authorship for the three core documentation files in your repository: README.md, man_1_simple_shell, and AUTHORS. Here’s a deeper look at each file’s role and best practices:

![Texte alternatif](https://github.com/Trice97/holbertonschool-simple_shell/blob/126d260fc17553c1957c0eae1b805e742fd55ecb/NoteGPT-Flowchart-1745486922777.png)
