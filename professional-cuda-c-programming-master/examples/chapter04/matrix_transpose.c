#include <stdio.h>
#include <stdlib.h>

void initialData(float *in,  const int size)
{
    for (int i = 0; i < size; i++)
    {
        //in[i] = rand() & 256 /10.0f; //100.0f;
        in[i] = (float)( rand() & 256)/10.0f; //100.0f;
    }

    return;
}

void printMatrix(float *in, const int nx, const int ny)
{
	for(unsigned row = 0; row < nx; ++row) {
		for(unsigned col = 0; col < ny; ++col) {
			printf("%.3f  ", in[row*ny+col]);
		}
		printf("\n");
	}
	return ;
}

void matrixTranspose(float *out,float *in,const int nx,const int ny)
{
	for(unsigned row = 0; row < nx; ++row) {
		for(unsigned col = 0; col < ny; ++col) {
			out[col*nx+row] = in[row*ny + col];
		}
		printf("\n");
	}
	return ;
}

int main(int argc, char const *argv[])
{
	int nx=5,ny=5;
	int nElem = nx*ny;
	float *in  = (float *)malloc(nElem);
	float *out = (float *)malloc(nElem);
    initialData(in,nx*ny);
    printMatrix(in,nx,ny);
    matrixTranspose(out,in,nx,ny);
    printMatrix(out,nx,ny);
	return 0;
}