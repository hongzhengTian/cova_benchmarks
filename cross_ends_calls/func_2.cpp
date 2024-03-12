#include <iostream>
#include <fstream>

// declare a function pointer type
typedef double (*Func1Ptr)(double, double);

int main() {
    std::ifstream file("func_addr.txt");
    uintptr_t func_addr;
    file >> func_addr;

    // convert the address to a function pointer
    Func1Ptr func_1 = reinterpret_cast<Func1Ptr>(func_addr);

    // function call
    double result = func_1(2.0, 3.0);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
