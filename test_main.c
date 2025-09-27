#include <stdio.h>

void print_hello() {
    printf("Hello from print_hello function!\n");
}

void print_message(const char *message) {
    printf("Message: %s\n", message);
}
int main() {
    printf("Hello, World!\n");
    int x = 10;
    int y = 20;
    int z = x + y;
    int i;
    printf("The sum of %d and %d is %d\n", x, y, z);
    print_hello();
    for(i = 0; i < 10; i++) {
        print_message("Inside the loop\n");
    }
    int *ptr;
    *ptr=10; // This will likely cause a segmentation fault
    printf("Value at ptr: %d\n", *ptr);
    return 0;
}