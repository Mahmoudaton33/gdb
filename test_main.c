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