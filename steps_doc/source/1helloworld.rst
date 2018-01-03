1helloword
=======================

1. stepsby 1hello 写最简单的cuda程序

::

 #include "../common/common.h"
 #include <stdio.h>
 
 /*
  * A simple introduction to programming in CUDA. This program prints "Hello
  * World from GPU! from 10 CUDA threads running on the GPU.
  */
 
 __global__ void helloFromGPU(int count)
 {
     for (int i=blockIdx.x * blockDim.x + threadIdx.x; i < count; i += blockDim.x * gridDim.x  )
     {
     printf("gridDim.x,%d | blockDim.x %d | blockIdx.x %d | threadIdx.x %d\n",gridDim.x,blockDim.x,blockIdx.x,threadIdx.x);
     printf("%d, Hello World from GPU!,blockIdx: %d,threadIdx:%d \n", i,blockIdx.x, threadIdx.x);
     }
 }
 
 
 
 int main(int argc, char **argv)
 {
     printf("Hello World from CPU!\n");
 
     helloFromGPU<<<5, 10>>>(50);
     
     CHECK(cudaDeviceReset());
     return 0;
 }
 


2. 了解cuda编程的主要步骤

- 1. Allocate GPU memories.
- 2. Copy data from CPU memory to GPU memory.
- 3. Invoke the CUDA kernel to perform program-specific computation.
- 4. Copy data back from GPU memory to CPU memory.
- 5. Destroy GPU memories.

3. 会用cmake来编译cuda程序

::

  cmake_minimum_required(VERSION 2.8)
  find_package(CUDA QUIET REQUIRED)
  #=============================================
  # Pass options to NVCC
  set( CUDA_NVCC_FLAGS ${CUDA_NVCC_FLAGS}; 
  -O3 -gencode arch=compute_50,code=sm_50
      -gencode arch=compute_60,code=sm_60
  )
  # Specify include directories
  #=============================================
  
  include_directories(
  ../common
  )
  
  #=============================================
  # Specify library paths
  #link_directories(
  #) 
  
  #=============================================
  # For compilation ...
  # Specify target & source files to compile it from
  cuda_add_executable(
  hello
  hello.cu
  ../common/common.h
  )
  #=============================================
  # For linking ...
  # Specify target & libraries to link it with
  # target_link_libraries(
  # )
  #=============================================
  
