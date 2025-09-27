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
gcc test_main.c -g -o main.out
