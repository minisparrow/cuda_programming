#include <stdio.h>

#define NUM_BLOCKS 16
#define BLOCK_WIDTH 1

__global__ 
void hello()
{
   printf("hello world, I am a thread in block %d\n",blockIdx.x);
}


int main(int argc, char **argv)
{
   // lauch the kernel
   hello<<<NUM_BLOCKS,BLOCK_WIDTH>>>();
    
   //force the printf() to flush
   cudaDeviceSynchronize();

   printf("That's all!\n");
   return 0;
}
