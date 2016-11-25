#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    int n;
    if(argc == 2)
    {
	n = atoi(argv[1]);
    }
    else
    {
	printf("Размер решета: ");
	scanf("%d", &n);
    }
    
    if(n < 1) n = 1;
    
    int byte = sizeof(argv[0][0]);
    int bytes = n / byte + (n % byte > 0);
    char* R = malloc(bytes);
    
    for(int i = 0; i < n; i++)
    {
	
    }
    
    for(int i = 0; i < n; i++)
    {
	R[i / byte] &= ~(1 << (i % byte));
    }
    
    return 0;
}