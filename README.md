# gdb Debugging 

## first step 
This guide demonstrates how to create a simple C program with a **segmentation fault**, compile it with debugging symbols, and use **GDB** to analyze and navigate the code.

---

## 1. create a c program with a segmentation fault error 

```c
#include <stdio.h>

int main() {
    int *ptr = NULL;   // NULL pointer
    *ptr = 10;         // Causes segmentation fault
    printf("Value: %d\n", *ptr);
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
Run the program from the beginning by writing :
```c
start 
```
Step through the code line by line:
```c
n
```
