#----------------------------------------------------------------------
# This file is an example of a CoVA input file that contains three
# large cascade GEMM kernels.
#----------------------------------------------------------------------

import numpy as np
# import cova

# define first large gemm kernel
# @cova(mode = 'codegen', backend = 'cpu')
def gemm_0(input_0, input_1):
    output_0 = np.dot(input_0, input_1)
    return output_0

# define second large gemm kernel
# @cova(mode = 'codegen', backend = 'gpu')
def gemm_1(input_0, input_1):
    output_0 = np.dot(input_0, input_1)
    return output_0
    
# define third large gemm kernel
# @cova(mode = 'codegen', backend = 'fpga')
def gemm_2(input_0, input_1):
    output_0 = np.dot(input_0, input_1)
    return output_0

# input data
input_0 = np.random.rand(8192, 8192)
input_1 = np.random.rand(8192, 8192)
input_2 = np.random.rand(8192, 8192)
input_3 = np.random.rand(8192, 8192)

import time
# call first large gemm kernel
start_kernel_0 = time.time()
output_0 = gemm_0(input_0, input_1)
end_kernel_0 = time.time()
time_kernel_0 = end_kernel_0 - start_kernel_0
print("Time taken for input_0: ", time_kernel_0)

# call second large gemm kernel
start_kernel_1 = time.time()
output_1 = gemm_1(output_0, input_2)
end_kernel_1 = time.time()
time_kernel_1 = end_kernel_1 - start_kernel_1
print("Time taken for input_1: ", time_kernel_1)

# call third large gemm kernel
start_kernel_2 = time.time()
output_2 = gemm_2(output_1, input_3)
end_kernel_2 = time.time()
time_kernel_2 = end_kernel_2 - start_kernel_2
print("Time taken for input_2: ", time_kernel_2)

total_time = time_kernel_0 + time_kernel_1 + time_kernel_2
print("Total time taken: ", total_time)

#----------------------------------------------------------------------
# Running all the three kernels on CPU
#----------------------------------------------------------------------
# Time taken for input_0:  3.2687129974365234
# Time taken for input_1:  3.3334639072418213
# Time taken for input_2:  3.2236173152923584
# Total time taken:  9.825794219970703
