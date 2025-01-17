#include <stdio.h>

int main(int argc,char **argv)
{
    const int ARRAY_SIZE = 10;
    
    int acc = 0;
    int out[ARRAY_SIZE];
    int elements[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    //exclusive scan
    for(int i = 0; i < ARRAY_SIZE; i++){
    	out[i] = acc;
    	acc = acc + elements[i];
    }

    //   //inclusive scan
    //   for(int i = 0; i < ARRAY_SIZE; i++){
    //   	acc = acc + elements[i];
    //   	out[i] = acc;
    //   }

    for(int i = 0 ; i < ARRAY_SIZE; i++){
    	printf("%4i ", elements[i]);
    }
     
    printf("\n-----\n");

    for(int i = 0 ; i < ARRAY_SIZE; i++){
    	printf("%4i ", out[i]);
    }
    printf("\n-----\n");

    return 0;
}
