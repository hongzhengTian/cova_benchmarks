#include <iostream>

// declare a function pointer type
typedef double (*Func1Ptr)(double, double);

int main() {
    uintptr_t func_addr = 12345678; // hard-coded address

    // convert the address to a function pointer
    Func1Ptr func_1 = reinterpret_cast<Func1Ptr>(func_addr);

    // function call
    double result = func_1(2.0, 3.0);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
