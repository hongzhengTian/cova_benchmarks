from numba import njit
from numba import cfunc, types
import ctypes

# Define and compile your function with Numba
@cfunc(types.double(types.double, types.double))
def add(x, y):
    return x + y

# Function to get the address of the compiled 'add' function
def get_add_func_address():
    func_address = add.address
    return ctypes.c_void_p(func_address).value
