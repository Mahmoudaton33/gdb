#include <iostream>

int main() {
    int arr[4] = {1, 2, 3, 4};
    arr[7] = 0xff0000dd; // This will likely cause undefined behavior
    std::cout << "Value at arr[7]: " << arr[7] << std::endl;

    return 0;
}