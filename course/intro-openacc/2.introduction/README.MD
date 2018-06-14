# Introduction to GPU programming with OpenACC

You will run your first application in OpenACC in order to verify that everything is working correctly. In addition, you will identify some of the main characteristics on [heterogeneous computing](https://en.wikipedia.org/wiki/Heterogeneous_computing) applications developed with OpenACC.

## Objectives

- [x] Understand why GPU programming has become a disruptive technology.
- [x] Understand some differences between GPU and CPU hardware.
- [x] Advantages of OpenACC
- [x] Running the first heterogenious application.


## Exercise 1

Copy and paste the code from [this](https://github.com/rmfarber/ParallelProgrammingWithOpenACC/blob/master/Chapter01/accFill_ex1.cpp) in the *acc-course* directory. Save it in a file called **accFill_ex1.cpp**. Read and try to understand what the code does. Ask quetions to your tutor.

## Exercise 2

Run the application **accFill_ex1.cpp**.

```bash
pgc++ -std=c++11 -acc -ta=multicore,tesla -Minfo=accel accFill_ex1.cpp -o accFill_ex1
```

```bash
export ACC_DEVICE_TYPE=host 
./accFill_ex1 1000 
```

```bash
export ACC_DEVICE_TYPE=nvidia 
./accFill_ex1 1000 
```