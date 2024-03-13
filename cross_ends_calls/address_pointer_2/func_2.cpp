#include <iostream>
#include <fstream>
#include <cstdint>

typedef double (*Func1Ptr)(double, double); // Function pointer type

int main() {
    std::ifstream file("func_ptr.txt");
    if (!file.is_open()) {
        std::cerr << "Unable to open the function pointer file." << std::endl;
        return 1;
    }

    uintptr_t func_addr;
    file >> func_addr;
    file.close();

    // Cast the read address to a function pointer
    Func1Ptr func_1 = reinterpret_cast<Func1Ptr>(func_addr);

    // Now call the function
    double result = func_1(2.0, 3.0);
    std::cout << "Result: " << result << std::endl;

    return 0;
}
