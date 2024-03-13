from numba import cfunc, types
import ctypes

@cfunc(types.double(types.double, types.double))
def func_1(x, y):
    return x + y

# store the address of the function
func_1_ptr = ctypes.c_void_p(func_1.address)
print(f"Function pointer address: {func_1_ptr.value}")

with open("func_addr.txt", "w") as f:
    f.write(str(func_1_ptr.value))
