# cova_benchmarks

## BlurCanny

  * `hls_proj`
    * All the vitis hls projects
    * In each sub-directory, run `vitis_hls script.tcl`
  * `blur_canny_cvlib.py`
    * Both Gaussian blur and Canny edge detection are using CV library.
  * `blur_cupy_canny_cupy.py`
    * Both Gaussian blur and Canny edge detection are using CuPy manually.
  * `blur_cupy_canny_numpy.py`
    * Gaussian blur uses CuPy manually, Canny edge detection uses NumPy manually.
  * `blur_cupy_cov_canny_cupy_conv.py`
    * Both Gaussian blur and Canny edge detection are using CuPy manually, but instead of implementing the Conv op manually, directly use the `cupyx.scipy.ndimage.convolve()` function.
  * `blur_numpy_canny_numpy.py`
    * Both Gaussian blur and Canny edge detection are using NumPy manually.

## MNIST

  * `mnist_torch.py`
    * Using simple MLP to implement MNIST handwriting number recolonization.
    * Including train and inference.
  * Download the dataset from [imagenet-mini](https://www.kaggle.com/datasets/ifigotin/imagenetmini-1000?resource=download) in this folder and unzip it.

## ResNet18

  * `resnet18.py`
    * Use predesigned resnet18 model.
    * Only include inference.

## cross_ends_calls

  * Try to test if it is possible to call a function cross different backend hardware.
    * For example, an FPGA host C++ code may call a Numba-acceleerated module in Python.
  * Tested three methods:
    * Directly pass the address pointer of the Numba function to the C++ code.
      * Segmentation fault Error
    * Using Numba Ahead-Of-Time.

      ```sh
      /usr/bin/ld: /tmp/cc1FBHcp.o: in function `main':
      func_2.cpp:(.text+0x25): undefined reference to `func_1'
      collect2: error: ld returned 1 exit status
      ```

      * However, it works in Python:

        ```sh
        >>> import my_module
        >>> my_module.func_1(3.0,4.0)
        7.0
        ```

    * Using `cffi` and called by C++.
      * It Works.