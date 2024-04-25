# C -  Simple Shell

# Table of Contents
1. [Description](#description)
2. [Flowchart](#flowchart)
3. [Output](#output)
4. [List of allowed functions and system calls](#list-of-allowed-functions-and-system-calls)
5. [Compilation](#Compilation)
6. [Testing](#testing)
7. [Checks](#checks)
8. [Simple Shell Dream Team](#sparkles-simple-shell-dream-team-sparkles)

## Description
This program is a custom implementation of the SHELL command line language interpreter. It was created as part of the final group project for sprint 1 Holberton School Australia Cohort 23.

## Flowchart
![shellflowchart](https://github.com/kdn95/holbertonschool-simple_shell/blob/main/shell_flowchart.png?raw=true)
## Output
- Unless specified otherwise, your program **must have the exact same output as** ```sh (/bin/sh)``` as well as the exact same error output.
- The only difference is when you print an error, the name of the program must be equivalent to your ```argv[0]``` (See below)
Example of error with ```sh```:

```
$ echo "qwerty" | /bin/sh
/bin/sh: 1: qwerty: not found
$ echo "qwerty" | /bin/../bin/sh
/bin/../bin/sh: 1: qwerty: not found
$
```

Same error with your program ```hsh```:

```
$ echo "qwerty" | ./hsh
./hsh: 1: qwerty: not found
$ echo "qwerty" | ./././hsh
./././hsh: 1: qwerty: not found
$

```
## List of allowed functions and system calls+
- all functions from string.h
- ```access``` (man 2 access)
- ```chdir```(man 2 chdir)
- ```close```(man 2 close)
- ```closedir``` (man 3 closedir)
- ```execve``` (man 2 execve)
- ```exit``` (man 3 exit)
- ```_exit``` (man 2 _exit)
- ```fflush``` (man 3 fflush)
- ```fork``` (man 2 fork)
- ```free``` (man 3 free)
- ```getcwd``` (man 3 getcwd)
- ```getline``` (man 3 getline)
- ```getpid``` (man 2 getpid)
- ```isatty``` (man 3 isatty)
- ```kill``` (man 2 kill)
- ```malloc``` (man 3 malloc)
- ```open``` (man 2 open)
- ```opendir``` (man 3 opendir)
- ```perror``` (man 3 perror)
- ```printf``` (man 3 printf)
- ```fprintf``` (man 3 fprintf)
- ```vfprintf``` (man 3 vfprintf)
- ```sprintf``` (man 3 sprintf)
- ```putchar``` (man 3 putchar)
- ```read``` (man 2 read)
- ```readdir``` (man 3 readdir)
- ```signal``` (man 2 signal)
- ```stat (__xstat)``` (man 2 stat)
- ```lstat (__lxstat)``` (man 2 lstat)
- ```fstat (__fxstat)``` (man 2 fstat)
- ```strtok``` (man 3 strtok)
- ```wait``` (man 2 wait)
- ```waitpid``` (man 2 waitpid)
- ```wait3``` (man 2 wait3)
- ```wait4``` (man 2 wait4)
- ```write``` (man 2 write)

## Installation
To install this program, clone this repository using the git clone command as shown below.
```bash
git clone https://github.com/kdn95/holbertonschool-simple_shell.git
```

## Usage 
**1. Compilation**<br>
Compile the program using a c compiler. For example, we have used GCC:
```C
gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```
This will compile all the '.c' files in the directory into an exectuable named hsh

**2. Run the program**<br>
After compiling all the files, you can run the program from the command line:
```bash
./hsh
```

**3. User Prompt**<br>
A ```$``` should be displayed, awaiting for a user command input:
```bash
$ [user command input]
```

## Compilation
Your shell will be compiled this way:

```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh
```

## Testing
Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

## Checks
The Checker will be released at the end of the project (1-2 days before the deadline). We **strongly** encourage the entire class to work together to create a suite of checks covering both regular tests and edge cases for each task. See ```task 8. Test suite```.
After the deadline, you will need to fork the repository if it's not on your Github account to be able to be corrected by the checker.

### :sparkles: Simple Shell Dream Team :sparkles:
- [Carole Zen-Ruffinen](https://github.com/crlzr)
- [Khang Nguyen](https://github.com/kdn95)
- [Nicole Ann Gorospe](https://github.com/NickelannG)
