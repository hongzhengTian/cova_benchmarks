#include <iostream>
#include <fstream>
#include <cstdint>
#include <Python.h>
// g++ -o func_2 func_2.cpp $(python3-config --cflags) $(python3-config --ldflags)


// Define the type of the function pointer
typedef double (*func_1_ptr_type)(double, double);

int main() {
    Py_Initialize(); // Initialize the Python interpreter
    // PyEval_InitThreads(); // Initialize Python threads and acquire the GIL

    std::ifstream file("func_ptr.txt");
    if (!file) {
        std::cerr << "Error opening func_ptr.txt" << std::endl;
        return 1;
    }

    // Read the function address from the file
    uintptr_t func_addr;
    file >> func_addr;
    file.close();

    // Cast the address to the function pointer type
    func_1_ptr_type func_1_ptr = reinterpret_cast<func_1_ptr_type>(func_addr);

    // Call the function
    // print type of func_1_ptr
    std::cout << "Type of func_1_ptr: " << typeid(func_1_ptr).name() << std::endl;

    double result = func_1_ptr(2.0, 3.0);
    std::cout << "Result: " << result << std::endl;

    Py_Finalize(); // Finalize the Python interpreter
    return 0;
}
