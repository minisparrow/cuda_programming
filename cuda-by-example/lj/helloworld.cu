#include <stdio.h>

__global__ void helloFromGPU(void)
{
	printf("hello world from GPU (block thread)%d,%d!\n",blockIdx.x,threadIdx.x);
	printf("blockdim %d,%d,%d\n",blockDim.x,blockDim.y,blockDim.z);
	printf("griddim %d,%d,%d\n",gridDim.x,gridDim.y,gridDim.z);
}

int main(int argc, char const *argv[])
{

	printf("hello world from cpu\n");

    dim3 grid(3);
    dim3 block(2);
	printf("block %d,%d,%d\n",block.x,block.y,block.z);
	printf("grid %d,%d,%d\n",grid.x,grid.y,grid.z);

	helloFromGPU<<<grid,block>>>();
	cudaDeviceReset();
	//cudaDeviceSynchronize();
	return 0;
}
