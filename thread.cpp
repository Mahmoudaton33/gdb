#include <iostream>
#include <thread>
#include <chrono>

int main() {
    int x = 0;
    int *ptr = nullptr;
    while(1)
    {   
        std::cout << "Thread is running...  ";
        std::cout << "Value of x: " << x << std::endl;
        x++;
        if(x==20)
        {
            *ptr = 10; // This will likely cause a segmentation fault
        }
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}