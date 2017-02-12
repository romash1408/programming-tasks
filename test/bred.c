#include <stdio.h>
#include <math.h>

int main()
{
	FILE *inp = fopen("bred.test1", "r");
	if(!inp){
		printf("Не удалось открыть файл.\n");
		return 1;
	}
	
	int n, mat[10000];
	while(!feof(inp))
	{
		fscanf(inp, "%d", mat + n++);
	}
	fclose(inp);
	
	int m = sqrt(n);
	if(m * m != n){
		printf("Матрица не квадратная\n");
		return 1;
	}
	
	 for(int i = 0; i < m; ++i)
	 {
	 	for(int j = 0; j < m; ++j)
	 	{
			printf("%5d", mat[i*m + j]);
	 	}
	 	printf("\n");
	 }
	
	return 0;
}