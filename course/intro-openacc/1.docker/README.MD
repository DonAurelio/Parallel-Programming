# Setting Up a Docker Container 

The course exercises will be held on docker containers. Containers allows the isolation of libraries or programs required for each individual project, i.e., if you have several projects and each project has its own container the libraries of one will not conflict with the libaries of others and so on. Another goodness with using containers is that you can save your container and run it on any computer running a Linux like OS.

## Requirements for Ubuntu 18.04

1. Install Nvidia GPU drivers: instalation guide for Ubuntu 18 can be found [here](https://linuxconfig.org/how-to-install-the-nvidia-drivers-on-ubuntu-18-04-bionic-beaver-linux)

2. Install the Ubuntu distribution for Docker: docker.io

```bash
sudo apt-get install docker.io
```

```bash
sudo groupadd docker
```

```bash
sudo usermod -aG docker $USER
```

```bash
sudo reboot now
```

```bash
docker run hello-world
```

3. Install Nvidia Docker: installation guide can be found [here](https://github.com/NVIDIA/nvidia-docker). this feature will allow containers to access the GPUs. If you installed succesfully nvidia-docker2, if your run the following command:

```bash
docker run --runtime=nvidia --rm nvidia/cuda nvidia-smi
```
you will get further info about your GPU displayed by a container, as shown bellow.

```bash
+-----------------------------------------------------------------------------+
| NVIDIA-SMI 390.48                 Driver Version: 390.48                    |
|-------------------------------+----------------------+----------------------+
| GPU  Name        Persistence-M| Bus-Id        Disp.A | Volatile Uncorr. ECC |
| Fan  Temp  Perf  Pwr:Usage/Cap|         Memory-Usage | GPU-Util  Compute M. |
|===============================+======================+======================|
|   0  Quadro K620         Off  | 00000000:03:00.0  On |                  N/A |
| 34%   47C    P8     1W /  30W |    626MiB /  1993MiB |      1%      Default |
+-------------------------------+----------------------+----------------------+
                                                                               
+-----------------------------------------------------------------------------+
| Processes:                                                       GPU Memory |
|  GPU       PID   Type   Process name                             Usage      |
|=============================================================================|
+-----------------------------------------------------------------------------+
```
If you got and error or an empty table is possible your device is not being detected or your system does not meet all the requirements. Please check them again before continuing.

## Experimentation environment

To perform the practices, we will use a container prepared with the PGI compiler. Fortunatelly, someone somewhere in the world has already installed the compiler and made it public in [Docker Hub](https://www.tutorialspoint.com/docker/docker_hub.htm) so we can use it.

```bash
docker pull hopobcn/pgi-ce
``` 

That is all. You did not have to install the **PGI Compiler** or deal with libraries and binaries. Now you have a ready to use PGI Compiler. However, if you need more libraries to run your application you can look for an image that meet the libraries you need in **Docker Hub**. Or you can take the PGI compiler image as base and intall other libraries. **Docker Hub** provides ready to use images prepared by other communities arround the world. All you have to do is to download the image and use it.

The PGI Compiler is a C/C++ compiler just like gcc (GNU compiler) or icc (Intel compiler). In particular, this compiler presents significant improvements regarding GPU computing with OpenACC compiler directives.

Open a new terminal and place it in the *Desktop* folder. Create a new folder called *acc-course* and get into it.

```bash
cd /home/<your user name>/Desktop
mkdir acc-course
cd acc-course
```
Now we will create our first container (or experimental environment). This container will be called *acc-course*, it will share the directory */acc-course* (in the container), with the directory */home/<your user name>/Desktop/acc-couse* (in your computer).

```bash
docker run --runtime=nvidia -it --name acc-course -v ${PWD}:/acc-course hopobcn/pgi-ce
```
*Voilà*, now you are inside your container ready to do science.

```bash
root@9abe8758aa21:/#
```

Lets check the GPU feactures using the following command.

```bash
root@9abe8758aa21:/# pgaccelinfo
```

If all is working well the command will show you the features of your GPU. If that is not the case it will show you the following message.

```bash
No accelerators found.
Try pgaccelinfo -v for more information
```


