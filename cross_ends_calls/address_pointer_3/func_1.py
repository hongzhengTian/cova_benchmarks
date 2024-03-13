from numba import cfunc, types

# Define the function signature
sig = types.double(types.double, types.double)

# Use the cfunc decorator to create a C-callable function
@cfunc(sig)
def func_1(x, y):
    return x + y

# The address attribute is available on the compiled function object
func_1_address = func_1.address

print(f"Address of func_1: {func_1_address}")

# Write the address to a file
with open('func_ptr.txt', 'w') as f:
    f.write(f"{func_1_address}\n")

