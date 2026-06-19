*Este proyecto ha sido creado como parte del currículo de 42 por durisosa.*
![License](https://img.shields.io/badge/license-MIT-blue)
![Version](https://img.shields.io/badge/version-1.0.0-green)   
![GitHub stars](https://img.shields.io/github/stars/dmsosa/REPO?style=social)

# Description.

Get next line is a function that allow us to read bytes from an open file "X", up to the next '\n' character, in other words, line by line.

# Instructions

1. Clone the repo with `git clone`;
2. This project has no Makefile, so only compiling the main will make you able to test it.
3. Copy this command to compile the mandatory part `gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g get_next_line.c get_next_line_utils.c main.c -o a.out`
4. Copy this command to compile the bonus `gcc -Wall -Wextra -Werror -Wl,--wrap=malloc -g get_next_line_bonus.c get_next_line_utils_bonus.c main.c -o a.out`
5. Execute the binary ./a.out

# Resources

The Manual ('man' command) of the Unix operating system, Google and Stack Overflow questions were used as the main sources of information.

Other support materials have been the GitHub repositories of other cursus students.

Students that inspired me a lot:

[youssef-be](https://github.com/youssef-benchaaboun)
[jdecorte-be](https://github.com/jdecorte-be)
[mcombeau](https://github.com/mcombeau)
[suspectedoceano](https://github.com/suspectedoceano)


## IA Usage:

I used the IA as a support to speed up the following tasks: 

a. Add shields to the README.md.
b. Filter best Stack Overflow answers to my questions
c. Summary information available on the internet
d. Investigating which smaller skills were needed to successfully understand this topic.

## About the function

This fucntion is recommended to be tested with `francinette` or `paco` to test it.


# EXPLAIN IT AS IF I'M 5 YEARS OLD:

# SOLUTION 1 jdecort-

if I read before entering the loop, the first time I read BUF_SIZE bytes from fd
now I join it to data, but what if data was already something? since if data is NULL,
just append buffer so data = 0 + buffer. If data was something then data = data + buffer 
but if I just miss BUF_SIZE to reach EOF?
then I reached EOF before entering the loop, so data = strjoin, and if not, I never enter the while loop so 
directly returns the same data as before

## what happens in strjoin if buf is NULL?

### case buf = static char[]
	if bufLen is null, ftstrlen returns 0, 
	if if strlenreturns0, ftcalloc has space for linelen or 0
	if buf is null, it means that my static char is initialized as null, but it wont happen, in any case, 
	if its first char is null. what would happen? then strlen returns 0
	so my copy wont append anything and joined will be malloced with nulls
### case buf = malloc char *
	if bufLen is null, ftstrlen returns 0, 
	and then?

### what does strjoin do?
	\n is added from the first time, in the first time, I have no newline in line as it is NULL 
	since it start as null, strlen returns 0, I malloc space only for 0 + buflen the first time 
	it will append until \n or until the end if buf has not found any \n yet 
	in further iterations, line is ensure to dont have \n, since if it has, in our gnl while loop it will be detected to have a \n and returned right away. 
	so if we are in another iteration it is implicit that it will not have any \n char

### why it frees the prev line?
	but I need to free the line, 
	what happens if i free it? 
	If i dont free and return the same line, 
	conditions do not change in our 
	line and eof > then return the line 
	if I free, then I wont be able to return it if I am in the eof
	I was not able to join until the newline...
	the malloc gave me error while creating a strjoin, 
	my program wont crash simply returns NULL, buf I left memory handling 
	if my malloc fails, i return NULL, and free the prev line so we directly return NULL 
	we do this since we are directly replacing line with the returned value, and not using any tmp variable

## Solution 2: youssef-be


## Solution 3: suspected oceano

#### ... to be continued.