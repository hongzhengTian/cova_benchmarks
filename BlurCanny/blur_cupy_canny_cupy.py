import numpy as np
import cupy as cp
import matplotlib.pyplot as plt
import time

def gaussian_kernel(size, sigma=1):
    size = int(size) // 2
    x, y = cp.mgrid[-size:size+1, -size:size+1]
    normal = 1 / (2.0 * cp.pi * sigma**2)
    g =  cp.exp(-((x**2 + y**2) / (2.0*sigma**2))) * normal
    return g

def convolve2d(image, kernel):
    kernel = kernel - kernel.mean()
    k_height, k_width = kernel.shape
    h, w = image.shape
    new_image = cp.zeros((h - k_height + 1, w - k_width + 1))
    for i in range(new_image.shape[0]):
        for j in range(new_image.shape[1]):
            new_image[i][j] = cp.sum(image[i:i+k_height, j:j+k_width] * kernel).astype(cp.float32)
    return new_image

def gaussian_blur(image, kernel_size):
    kernel = gaussian_kernel(kernel_size, sigma=cp.sqrt(kernel_size))
    return convolve2d(image, kernel)

def sobel_filters(img):
    Kx = cp.array([[-1, 0, 1], [-2, 0, 2], [-1, 0, 1]], cp.float32)
    Ky = cp.array([[1, 2, 1], [0, 0, 0], [-1, -2, -1]], cp.float32)

    Ix = convolve2d(img, Kx)
    Iy = convolve2d(img, Ky)

    G = cp.hypot(Ix, Iy)
    G = G / G.max() * 255
    theta = cp.arctan2(Iy, Ix)
    return (G, theta)

def non_max_suppression(img, D):
    M, N = img.shape
    Z = cp.zeros((M,N), dtype=cp.float32)
    angle = D * 180. / cp.pi
    angle[angle < 0] += 180

    for i in range(1,M-1):
        for j in range(1,N-1):
            try:
                q = 255
                r = 255

                #angle 0
                if (0 <= angle[i,j] < 22.5) or (157.5 <= angle[i,j] <= 180):
                    q = img[i, j+1]
                    r = img[i, j-1]
                #angle 45
                elif (22.5 <= angle[i,j] < 67.5):
                    q = img[i+1, j-1]
                    r = img[i-1, j+1]
                #angle 90
                elif (67.5 <= angle[i,j] < 112.5):
                    q = img[i+1, j]
                    r = img[i-1, j]
                #angle 135
                elif (112.5 <= angle[i,j] < 157.5):
                    q = img[i-1, j-1]
                    r = img[i+1, j+1]

                if (img[i,j] >= q) and (img[i,j] >= r):
                    Z[i,j] = img[i,j]
                else:
                    Z[i,j] = 0

            except IndexError as e:
                pass
    
    return Z

def threshold(img, lowThresholdRatio=0.05, highThresholdRatio=0.09):
    highThreshold = img.max() * highThresholdRatio
    lowThreshold = highThreshold * lowThresholdRatio
    
    M, N = img.shape
    res = cp.zeros((M,N), dtype=cp.int32)
    
    weak = cp.int32(25)
    strong = cp.int32(255)
    
    strong_i, strong_j = cp.where(img >= highThreshold)
    zeros_i, zeros_j = cp.where(img < lowThreshold)
    
    weak_i, weak_j = cp.where((img <= highThreshold) & (img >= lowThreshold))
    
    res[strong_i, strong_j] = strong
    res[weak_i, weak_j] = weak
    
    return res


def hysteresis(img, weak, strong=255):
    M, N = img.shape
    for i in range(1, M-1):
        for j in range(1, N-1):
            if (img[i,j] == weak):
                try:
                    if ((img[i+1, j-1] == strong) or (img[i+1, j] == strong) or (img[i+1, j+1] == strong)
                        or (img[i, j-1] == strong) or (img[i, j+1] == strong)
                        or (img[i-1, j-1] == strong) or (img[i-1, j] == strong) or (img[i-1, j+1] == strong)):
                        img[i, j] = strong
                    else:
                        img[i, j] = 0
                except IndexError as e:
                    pass
    return img

def canny_edge_detector(img):
    gradientMat, thetaMat = sobel_filters(img)
    nonMaxImg = non_max_suppression(gradientMat, thetaMat)
    thresholdImg = threshold(nonMaxImg)
    img_final = hysteresis(thresholdImg, weak=75)
    return img_final

def process_image(image):
    # data density sensitive task: blurring
    start_blur = time.time()
    blurred_image = gaussian_blur(image, kernel_size=11)
    end_blur = time.time()
    print(f'Blurring time in manual: {end_blur - start_blur:.6f} seconds')
    
    # latency sensitive task: edge detection
    start_edge = time.time()
    edges = canny_edge_detector(blurred_image)
    end_edge = time.time()
    print(f'Edge detection time in manual: {end_edge - start_edge:.6f} seconds')

    print(f'Total time in manual: {end_edge - start_blur:.6f} seconds')
    
    return blurred_image, edges

image = plt.imread('spiderman.jpg')
image = np.mean(image, axis=2)
image = cp.array(image)
blurred_image, edges = process_image(image)

# plt.figure(figsize=(20, 20))
# plt.subplot(131), plt.imshow(image, cmap='gray'), plt.title('Original Image')
# plt.subplot(132), plt.imshow(blurred_image, cmap='gray'), plt.title('Blurred Image')
# plt.subplot(133), plt.imshow(edges, cmap='gray'), plt.title('Canny Edge Detector')
# plt.show()
