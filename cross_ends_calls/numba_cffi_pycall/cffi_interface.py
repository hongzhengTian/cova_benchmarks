from cffi import FFI
from numba_function import get_add_func_address

ffi = FFI()

# Define the signature of our C function
ffi.cdef("""
    double add(double x, double y);
""")

# Load the address of the Numba-compiled function
add_func_addr = get_add_func_address()

# Create a C function pointer to the Numba-compiled function
print(f"Function pointer address: {add_func_addr}")
add_cfunc = ffi.cast("double(*)(double, double)", add_func_addr)

# Wrapper function to call the Numba-compiled function from Python
def call_add(x, y):
    result = add_cfunc(x, y)
    return result
