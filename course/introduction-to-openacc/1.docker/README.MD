# Setting Up a Docker Container 

The practices of the course will be held on docker containers. Containers allows the isolation of each individual experiment or practice, i.e, if you have several proyects and each proyect has its own container the libraries of one does not conflict with the libaries of others and so on. Another goodness with using containers is that you can save your container and run it on any computer running a Linux like OS (*experimental reproducibility*).

## Requirements

* **docker.io**: Ubuntu distribution of Docker.
* [nvidia-docker](https://github.com/nvidia/nvidia-docker/wiki/Installation-(version-2.0)): Enable to Docker conatiners the NVIDIA GPUs capabilities.