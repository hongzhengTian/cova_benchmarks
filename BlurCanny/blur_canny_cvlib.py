import numpy as np
import cv2
from skimage import feature
import matplotlib.pyplot as plt
import time

def process_image(image):
    # data density sensitive task: blurring
    start_blur = time.time()
    blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
    end_blur = time.time()
    print(f'Blurring time in CV2: {end_blur - start_blur:.6f} seconds')
    
    # latency sensitive task: edge detection
    start_edge = time.time()
    edges = feature.canny(blurred_image, sigma=3)
    end_edge = time.time()
    print(f'Edge detection time in CV2: {end_edge - start_edge:.6f} seconds')

    print(f'Total time in CV2: {end_edge - start_blur:.6f} seconds')
    
    return edges


image = cv2.imread('spiderman.jpg', cv2.IMREAD_GRAYSCALE)
if image is None:
    print('Image not found')
else:
    processed_image = process_image(image)

    plt.figure(figsize=(12, 6))
    plt.subplot(121)
    plt.imshow(image, cmap='gray')
    plt.title('Original Image')

    plt.subplot(122)
    plt.imshow(processed_image, cmap='gray')
    plt.title('Processed Image')
    plt.show()
