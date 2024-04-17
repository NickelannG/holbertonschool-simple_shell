# PROJECT NAME 
Everything you need to know to start coding your own shell

## Description
Exercises to do before starting the C- Simple Shell project for Holberton School Australia cohort 23
### Exercises
**PID & PPID**
<ol start="0">
<li>getppid
Write a program that prints the PID of the parent process. Run your program several times within the same shell. It should be the same. Does echo $$ print the same value? Why?</li>

<li>/proc/sys/kernel/pid_max
Write a shell script that prints the maximum value a process ID can be.</li>
</ol>

**Arguments**
<ol start="0">
<li> av
Write a program that prints all the arguments, without using ac.</li>
<li>Read line
Write a program that prints "$ ", wait for the user to enter a command, prints it on the next line.</li>
</ol>

**Fork, wait and execve**
Write a program that executes the command ls -l /tmp in 5 different child processes. Each child should be created by the same process (the father). Wait for a child to exit before creating a new child.

**Super Simple Shell**
Using everything we saw, write a first version of a super simple shell that can run commands with their full path, without any argument.

**Find a file in the PATH**
Write a program that looks for files in the current PATH.
Usage: _which filename ...

**Environement**
<ol start="0">
<li>printenv with environ
Write a program that prints the environment using the global variable environ.</li>
<li>env vs environ
Write a program that prints the address of env (the third parameter of the main function) and environ (the global variable). Are they they same? Does this make sense?</li>
<li>getenv()
Write a function that gets an environment variable. (without using getenv)
Prototype: char *_getenv(const char *name);</li>
<li>PATH
Write a function that prints each directory contained in the the environment variable PATH, one directory per line.</li>
<li>PATH
Write a function that builds a linked list of the PATH directories.</li>
<li>setenv
Write a function that changes or adds an environment variable (without using setenv).
Prototype: int _setenv(const char *name, const char *value, int overwrite);</li>
<li>unsetenv
Write a function that deletes the variable name from the environment (without using unsetenv).
Prototype: int _unsetenv(const char *name);</li>
</ol>

### :sparkles: Simple Shell Dream Team :sparkles:
- [Carole Zenruffinen](https://github.com/crlzr)
- [Khang Nguyen](https://github.com/kdn95)
- [Nicole Ann Gorospe](https://github.com/NickelannG)
