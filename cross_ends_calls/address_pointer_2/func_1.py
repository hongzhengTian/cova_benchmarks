from numba import cfunc, types, njit
import ctypes

# Define the function signature
signature = types.double(types.double, types.double)

# Use the njit decorator for better error messages
@cfunc(signature)
def func_1(x, y):
    return x + y

# Compile the function to machine code with cfunc
compiled_func = cfunc(signature)(func_1)

# Save the address of the compiled function to a file
func_addr = compiled_func.address
with open('func_ptr.txt', 'w') as f:
    f.write(f"{func_addr}\n")
