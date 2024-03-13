#include <iostream>
// python func_1.py

// mv my_module.cpython-311-x86_64-linux-gnu.so libmy_module.so
// g++ -o func_2 func_2.cpp -L. -lmy_module
// // or g++ -o func_2 func_2.cpp ./my_module.cpython-311-x86_64-linux-gnu.so

// ./func_2

// Declare the function prototype
extern "C" {
    double func_1(double x, double y);
}

int main() {
    double result = func_1(2.0, 3.0);
    std::cout << "Result: " << result << std::endl;
    return 0;
}

