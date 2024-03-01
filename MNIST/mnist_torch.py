import torch
import torch.nn as nn
import torch.optim as optim
import torchvision
import torchvision.transforms as transforms
import matplotlib.pyplot as plt
import numpy as np
import time


class SimpleNet(nn.Module):
    def __init__(self):
        super(SimpleNet, self).__init__()
        self.fc1 = nn.Linear(784, 512) 
        self.fc2 = nn.Linear(512, 256) 
        self.fc3 = nn.Linear(256, 128)
        self.fc4 = nn.Linear(128, 64)
        self.fc5 = nn.Linear(64, 10)  

    def forward(self, x):
        x = torch.flatten(x, 1)
        x = torch.relu(self.fc1(x))
        x = torch.relu(self.fc2(x))
        x = torch.relu(self.fc3(x))
        x = torch.relu(self.fc4(x))
        x = self.fc5(x)
        return x

def train_model(model, trainloader, criterion, optimizer, device, epochs=2):
    model.train()
    total_batches = len(trainloader)
    print_interval = total_batches // 5
    for epoch in range(epochs):
        running_loss = 0.0
        for i, data in enumerate(trainloader, 0):
            inputs, labels = data[0].to(device), data[1].to(device)
            optimizer.zero_grad()
            outputs = model(inputs)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()
            running_loss += loss.item()
            if i % print_interval == print_interval - 1:
                # print(f'[Epoch: {epoch + 1}, Batch: {i + 1}/{total_batches}] Loss: {running_loss / print_interval:.3f}')
                running_loss = 0.0
    # print('Finished Training')

# model inference
def infer_model(model, testloader, device):
    model.eval()
    correct = 0
    total = 0
    # all_predicted = []
    # images_to_show = []
    with torch.no_grad():
        for data in testloader:
            images, labels = data[0].to(device), data[1].to(device)
            outputs = model(images)
            _, predicted = torch.max(outputs.data, 1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()
            # all_predicted.extend(predicted.cpu().numpy())
            # images_to_show.extend(images.cpu())
    # print(f'Accuracy of the network on the test images: {100 * correct // total} %')
    # return images_to_show, all_predicted
            
# one image inference
def infer_single_image(model, image, device):
    model.eval()
    with torch.no_grad():
        image = image.to(device)
        output = model(image)
        _, predicted = torch.max(output.data, 1)
    return predicted.item()

def imshow(img, label, predicted):
    img = img / 2 + 0.5  # unnormalize
    npimg = img.numpy()
    plt.imshow(np.transpose(npimg, (1, 2, 0)))
    plt.title(f'True label: {label} - Predicted: {predicted}')
    plt.show()

def main():
    batch_size = 8
    num_workers = 24
    transform = transforms.Compose([transforms.ToTensor(), transforms.Normalize((0.5,), (0.5,))])
    trainset = torchvision.datasets.MNIST(root='./data', train=True, download=True, transform=transform)
    trainloader = torch.utils.data.DataLoader(trainset, batch_size=batch_size, shuffle=True, num_workers=num_workers)
    testset = torchvision.datasets.MNIST(root='./data', train=False, download=True, transform=transform)
    testloader = torch.utils.data.DataLoader(testset, batch_size=batch_size, shuffle=False, num_workers=num_workers)

    # show the number of images in the train and test sets
    print(f'Train set size: {len(trainset)}')
    print(f'Test set size: {len(testset)}')

    device_cpu = torch.device("cpu")
    print('============================================================')
    print(f'Using {device_cpu}')
    print('============================================================')
    
    model = SimpleNet().to(device_cpu)
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(model.parameters(), lr=0.001, momentum=0.9)

    start_time_train = time.time()
    train_model(model, trainloader, criterion, optimizer, device_cpu)
    end_time_train = time.time()

    print(f'Training time: {end_time_train - start_time_train:.2f} seconds')

    start_time_infer = time.time()
    # images_to_show, all_predicted = infer_model(model, testloader, device_cpu)
    infer_model(model, testloader, device_cpu)
    end_time_infer = time.time()

    print(f'Inference the whole test set time: {end_time_infer - start_time_infer:.2f} seconds')
    print(f'Inference a single image time: {(end_time_infer - start_time_infer) / len(testset):.9f} seconds')

    print(f'Total time for training and evaluation: {end_time_infer - start_time_train:.2f} seconds')
    
    start_time_infer_single = time.time()
    image, label = testset[0]
    predicted = infer_single_image(model, image, device_cpu)
    end_time_infer_single = time.time()

    print(f'Inference a single image time: {end_time_infer_single - start_time_infer_single:.9f} seconds')

    # show the single image prediction
    # imshow(torchvision.utils.make_grid(image), label, predicted)

    device_gpu = torch.device("cuda:0" if torch.cuda.is_available() else "cpu")
    print('============================================================')
    print(f'Using {device_gpu}')
    print('============================================================')

    
    model = SimpleNet().to(device_gpu)
    criterion = nn.CrossEntropyLoss()
    optimizer = optim.SGD(model.parameters(), lr=0.001, momentum=0.9)

    start_time_train = time.time()
    train_model(model, trainloader, criterion, optimizer, device_gpu)
    end_time_train = time.time()

    print(f'Training time: {end_time_train - start_time_train:.2f} seconds')

    start_time_infer = time.time()
    # images_to_show, all_predicted = infer_model(model, testloader, device_gpu)
    infer_model(model, testloader, device_gpu)
    end_time_infer = time.time()

    print(f'Inference the whole test set time: {end_time_infer - start_time_infer:.2f} seconds')
    print(f'Inference a single image time: {(end_time_infer - start_time_infer) / len(testset):.9f} seconds')

    print(f'Total time for training and evaluation: {end_time_infer - start_time_train:.2f} seconds')

    start_time_infer_single = time.time()
    predicted = infer_single_image(model, image, device_gpu)
    end_time_infer_single = time.time()

    print(f'Inference a single image time: {end_time_infer_single - start_time_infer_single:.9f} seconds')

    # show the single image prediction
    # imshow(torchvision.utils.make_grid(image), label, predicted)

    # for i in range(4):
    #     imshow(torchvision.utils.make_grid(images_to_show[i]), testset[i][1], all_predicted[i])

if __name__ == '__main__':
    main()