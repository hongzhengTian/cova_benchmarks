from numba.pycc import CC
from numba import types

cc = CC('my_module')

@cc.export('func_1', types.double(types.double, types.double))
def func_1(x, y):
    return x + y

if __name__ == "__main__":
    cc.compile()

