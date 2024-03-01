# cova_benchmarks_testing

## BlurCanny

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
