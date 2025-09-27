# gdb Debugging 

## first step 
This guide demonstrates how to create a simple C program with a **segmentation fault**, compile it with debugging symbols, and use **GDB** to analyze and navigate the code.

---

## 1. create a c program with a segmentation fault error 

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    int x = 10;
    int y = 20;
    int z = x + y;
    printf("The sum of %d and %d is %d\n", x, y, z);

    int *ptr;
    *ptr=10; // This will likely cause a segmentation fault
    printf("Value at ptr: %d\n", *ptr);
    return 0;
}
```
## 2. compile with debugging symbols 

--- 
```c
gcc test_main.c -g -o main.out
```
## 3. start gdb

```c
gdb ./main.out
```
## 4. View the source code in TUI Mode(terminal user interface)
inside gdb press 
```c
ctr + x then a
```
This enables TUI (Text User Interface) mode, which shows the source code and allows navigation.

## 5. start debugging 
Start the program from the beginning by writing :
```c
start 
```
Step through the code line by line:
```c
n
```
printing variable value for example x:
```c
p x
```
also you can run the code by the following:
```c
run
```
or just type
```c
r
```
### Lets see more gdb comands (step, refresh, c, finish, bt, quit, & etc)
inside the TUI if you see the code not organised write the following:
```c
refresh
```
if you want to step into a function write the following:
```c
s
```
or
```c
step
```
if you want to exit the current function:
```c
finish
```
if you want to make the program to continue:
```c
c
```
if you want to exit the gdb session:
```c
quit
```


