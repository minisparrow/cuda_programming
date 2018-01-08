3_CheckDimension从Host,Device端访问维度
=========================================
- 1. 如何从Host端访问grid和block
     
     - grid(grid.x,grid.y, grid.z)
     - block(block.x,block.y,block,z)

- 2. 如何从Device端访问grid和block
     
     - gridDim(gridDim.x, gridDim.y, gridDim.z)
     - blockDim(blockDim.x, blockDim.y, blockDim.z)
     - blockIdx.x, ... 
     - threadIdx.x, ...

- 3. 例子 

::

  #include "../common/common.h"
  #include <cuda_runtime.h>
  #include <stdio.h>
  
  /*
   * Display the dimensionality of a thread block and grid from the host and
   * device.
   */
  
  __global__ void checkIndex(void)
  {
      printf("threadIdx:(%d, %d, %d)\n", threadIdx.x, threadIdx.y, threadIdx.z);
      printf("blockIdx:(%d, %d, %d)\n", blockIdx.x, blockIdx.y, blockIdx.z);
  
      printf("blockDim:(%d, %d, %d)\n", blockDim.x, blockDim.y, blockDim.z);
      printf("gridDim:(%d, %d, %d)\n", gridDim.x, gridDim.y, gridDim.z);
  
  }
  
  int main(int argc, char **argv)
  {
      // define total data element
      int nElem = 6;
  
      // define grid and block structure
      dim3 block(3);
      dim3 grid((nElem + block.x - 1) / block.x);
  
      // check grid and block dimension from host side
      printf("grid.x %d grid.y %d grid.z %d\n", grid.x, grid.y, grid.z);
      printf("block.x %d block.y %d block.z %d\n", block.x, block.y, block.z);
  
      // check grid and block dimension from device side
      checkIndex<<<grid, block>>>();
  
      // reset device before you leave
      CHECK(cudaDeviceReset());
  
      return(0);
  }
  
