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


