2gridBlock
====================
目标:学会如何定义grid和Block

- 1.明确概念: 

   grid中定义一个grid中有几个block, block 中定义一个block有几个thread 


- 2. 用dim3来定义block和grid

::

    dim3 block (1024);
    dim3 grid  ((nElem + block.x - 1) / block.x);

- 3. 用grid.x来访问block的index, 用block.x来访问thread的index 


- 4. 程序

::

 #include "../common/common.h"
 #include <cuda_runtime.h>
 #include <stdio.h>
 
 /*
  * Demonstrate defining the dimensions of a block of threads and a grid of
  * blocks from the host.
  */
 
 int main(int argc, char **argv)
 {
     // define total data element
     int nElem = 1024;
 
     // define grid and block structure
     dim3 block (1024);
     dim3 grid  ((nElem + block.x - 1) / block.x);
     printf("grid.x %d block.x %d \n", grid.x, block.x);
 
     // reset block
     block.x = 512;
     grid.x  = (nElem + block.x - 1) / block.x;
     printf("grid.x %d block.x %d \n", grid.x, block.x);
 
     // reset block
     block.x = 256;
     grid.x  = (nElem + block.x - 1) / block.x;
     printf("grid.x %d block.x %d \n", grid.x, block.x);
 
     // reset block
     block.x = 128;
     grid.x  = (nElem + block.x - 1) / block.x;
     printf("grid.x %d block.x %d \n", grid.x, block.x);
 
     // reset device before you leave
     CHECK(cudaDeviceReset());
 
     return(0);
 }
 


