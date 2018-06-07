# Docker Conatiner for GPU Programming

The course exercises will be held on **Docker containers**. Containers allows the isolation of the libraries required for you experiment to work properly. If you have several projects and each project resides on its own container the libraries of one will not conflict with the libaries of others and so on. Another goodness with using containers is that you can save your container and run it on any computer running a Linux like OS. It means that you do not have to reinstall the libraries you already set in you conatiner again (experimental reproducibility).

## Installing Ubuntu GPU Drivers, Docker and Nvidia Docker

On this section we will prepare our Docker conatiner to run the GPU applications developed in the present couse.

1. Install Nvidia GPU drivers: instalation guide for Ubuntu 18.04 can be found [here](https://linuxconfig.org/how-to-install-the-nvidia-drivers-on-ubuntu-18-04-bionic-beaver-linux)

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
If Docker installation was carried out correctly, the previous command had to have yielded something like:

```bash
Hello from Docker!
This message shows that your installation appears to be working correctly.

To generate this message, Docker took the following steps:
 1. The Docker client contacted the Docker daemon.
 2. The Docker daemon pulled the "hello-world" image from the Docker Hub.
    (amd64)
 3. The Docker daemon created a new container from that image which runs the
    executable that produces the output you are currently reading.
 4. The Docker daemon streamed that output to the Docker client, which sent it
    to your terminal.

To try something more ambitious, you can run an Ubuntu container with:
 $ docker run -it ubuntu bash

Share images, automate workflows, and more with a free Docker ID:
 https://hub.docker.com/

For more examples and ideas, visit:
 https://docs.docker.com/engine/userguide/

```

3. Install Nvidia Docker 2: installation guide can be found [here](https://github.com/NVIDIA/nvidia-docker). Nvidia Docker allow containers to access the your computer GPU.

After having nvidia docker installer, test your installation by executing the following command:

```bash
docker run --runtime=nvidia --rm nvidia/cuda nvidia-smi
```

If Nvidia Docker 2 installation was carried out correctly, you will get further info about your GPU displayed by a container, as shown bellow:

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

## The first Docker Container

To perform the practices, we will use a container provided with the PGI compiler. Fortunately, someone in the docker community already installed that compiler in a container and shared it through [Docker Hub](https://www.tutorialspoint.com/docker/docker_hub.htm) so we can use it. 

```bash
docker pull hopobcn/pgi-ce
``` 

That is all. You did not have to install the **PGI Compiler** or deal with libraries and binaries. Now you have a ready to use PGI Compiler. However, if you need more libraries to run your application you can look for an image that meets the libraries you need in **Docker Hub**. Or you can take the PGI compiler image as base and intall other libraries. **Docker Hub** provides ready to use images prepared by other communities arround the world. All you have to do is to download the image and use it.

The PGI Compiler is a C/C++ compiler just like gcc (GNU compiler) or icc (Intel compiler). In particular, this compiler presents significant improvements regarding GPU computing with OpenACC compiler directives desired for this course.

Open a new terminal and place it in the *Desktop* folder. Create a new folder called *acc-course* and get into it.

```bash
cd /home/<your user name>/Desktop
mkdir acc-course
cd acc-course
```
Now we will create our first container (experimental environment). This container will be called *acc-course*, it will share the directory */acc-course* (in the container), with the directory */home/<your user name>/Desktop/acc-couse* (in your computer).

```bash
docker run --runtime=nvidia -it --name acc-course -v ${PWD}:/acc-course hopobcn/pgi-ce
```
*Voilà*, now you are inside your container ready to do science.

```bash
root@9abe8758aa21:/#
```
Let's ask the container to show us the GPU's characteristics:

```bash
root@9abe8758aa21:/# pgaccelinfo
```

To exit from the conatiner type *exit*

```bash
root@9abe8758aa21:/# exit
```

To run your *acc-course* conatiner use:

```bash
docker start -ia acc-course
```

Then you will get into the container again

```bash
root@9abe8758aa21:/# 
```

## Installing Other packages to the Conatiner

Inside the conatiner use the following command to check your conatiner has access to internet

```bash
root@9abe8758aa21:/# apt-get update
```

In case the command fails, we must configure the internet access for the containers as follows:

1. Exit the container 

```bash
root@9abe8758aa21:/# exit
```

2. Check the available DNS in your computer

```bash
nmcli dev show | grep 'IP4.DNS'
```

*nmcli* command will show you one or more IPs.

```bash
IP4.DNS[1]:                             10.0.0.2
```

3. Edit the file */etc/docker/daemon.json*

```bash
nano /etc/docker/daemon.json
```

Add the *dns* keyword and place one of the IPs (e.g., 10.0.0.2) that shows the *nmcli* command and save the file.

```bash 
{
    "runtimes": {
        "nvidia": {
            "path": "/usr/bin/nvidia-container-runtime",
            "runtimeArgs": []
        }
    },
    "dns": ["10.0.0.2"]
}

```

4. Restart Docker 

```bash
sudo service docker restart
```

5. Try to install new packages in your container. Detailed information on how to solve the problems of internet connection of containers can be found [here](https://development.robinwinslow.uk/2016/06/23/fix-docker-networking-dns/).