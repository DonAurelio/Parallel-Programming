# Kernels and Parallel Directive

OpenACC comprise two directives to tell the compiler how your application must be parallelized. The **kernels** and **parallel** directives. 

The **parallel** directive tells the compiler to start a team of threads where each thread will execute sequentialy the code enclosed by this directive. Combining the parallel directive with the loop directive. i.e., a **parallel loop** directive will tell the compiler to create a team of threads on which each thread will perform one operation of the loop. For example, if a loop processes a vector, each thread will be assigned to a single vector position to perform an operation.

The **kernels** directive relies in the compiler capabilities to identify parallelism
in your application. Some times you need to probide to the kernels directive more information about your code so that kernels direcrive can parallelize your code correctly. 


## Objectives

- [x] Overview of the past class “the parallel construct and copyin” 
- [x] Understand how does the kernels construct works. 
- [x] Understand the differences between the parallel and kernels directive.
- [x] The basic concepts of data-parallel and task parallel programming.}


## Exercise 1

Copy and paste the code from [this](https://github.com/rmfarber/ParallelProgrammingWithOpenACC/blob/master/Chapter01/accFill_ex2.cpp) in the *acc-course* directory. Save it in a file called **accFill_ex2.cpp**. Read and try to understand what the code does. Ask quetions to your tutor.

## Exercise 2

Compile the **accFill_ex2.cpp** application.

```bash
pgc++ -std=c++11 -acc -ta=multicore,tesla -Minfo=accel accFill_ex2.cpp -o accFill_ex2
```

Run the application, additionaly use the *time* command to check how much time does the application expend to finish its work.

```bash
time ./accFill_ex2
```