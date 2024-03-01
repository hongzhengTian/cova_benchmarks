import torch
import torchvision
import torchvision.transforms as transforms
from torchvision.models.resnet import resnet18
import time
import os
import subprocess

def get_gpu_power_usage():
    power_draw = subprocess.check_output(['nvidia-smi', '--query-gpu=power.draw', '--format=csv,noheader,nounits']).decode('utf-8')
    return float(power_draw)

# Load the ResNet18 model 
model_path = 'model/resnet18.pth'
model = resnet18()
model.load_state_dict(torch.load(model_path))

# Prepare the ImageNet1000 dataset
data_transform = transforms.Compose([
    transforms.Resize(256),
    transforms.CenterCrop(224),
    transforms.ToTensor(),
    transforms.Normalize(mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225]),
])

# Assuming you have your ImageNet data in 'imagenet_data' directory
dataset = torchvision.datasets.ImageFolder(root='imagenet-mini/val', transform=data_transform)
dataloader = torch.utils.data.DataLoader(dataset, batch_size=1, shuffle=False) # Batch size set to 1 for per-image inference

# Function to test model performance
def test_model_only_inference(model, device):
    model.to(device)
    model.eval()

    total_images = len(dataset)
    total_time = 0

    with torch.no_grad():
        for inputs, _ in dataloader:
            inputs = inputs.to(device)
            start_time = time.time()
            outputs = model(inputs)
            total_time += time.time() - start_time

    avg_time_per_image = total_time / total_images
    fps = 1 / avg_time_per_image

    print(f"Total Images: {total_images}")
    print(f"Total Inference Time: {total_time:.2f} seconds")
    print(f"Average Inference Time per Image: {avg_time_per_image:.5f} seconds")
    print(f"Frames Per Second (FPS): {fps:.2f}")

# Test on CPU
device_cpu = torch.device('cpu')
print("Testing on CPU (only Inferencing)")
test_model_only_inference(model, device_cpu)

# Test on GPU, if available
if torch.cuda.is_available():
    device_gpu = torch.device('cuda:0')
    print("\nTesting on GPU (only Inferencing)")
    power_start = get_gpu_power_usage()
    test_model_only_inference(model, device_gpu)
    power_end = get_gpu_power_usage()
    print(f"Approximate GPU Power Consumption: {power_end - power_start} Watts")
else:
    print("GPU not available, skipping GPU tests.")


# Function to test model performance
def test_model_total(model, device):
    model.to(device)
    model.eval()

    total_images = len(dataset)

    start_time = time.time()
    with torch.no_grad():
        for inputs, _ in dataloader:
            inputs = inputs.to(device)
            outputs = model(inputs)
    end_time = time.time()

    print(f"Total Images: {total_images}")
    print(f"Total Time including Data Transfer: {end_time - start_time:.2f} seconds")
    print(f"Average Time per Image including Data Transfer: {(end_time - start_time) / total_images:.5f} seconds")
    print(f"Frames Per Second (FPS): {total_images / (end_time - start_time):.2f}")

# Test on CPU
device_cpu = torch.device('cpu')
print("\nTesting on CPU (Total time including Data Transfer)")
test_model_total(model, device_cpu)

# Test on GPU, if available
if torch.cuda.is_available():
    device_gpu = torch.device('cuda:0')
    print("\nTesting on GPU (Total time including Data Transfer)")
    test_model_total(model, device_gpu)
else:
    print("GPU not available, skipping GPU tests.")
