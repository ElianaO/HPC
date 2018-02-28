#include<stdio.h>
#include<stdlib.h>

void llenarMatriz(float **matriz, int size)
{ 
	int i,j;
	for (i=0;i < size; i++)
	{
		for (j=0; j < size; j++)
		{	
			matriz[i][j]=(float)(rand() / 11.0);
		}
	}
}

void imprimirMatriz(float **matriz, int size)
{


		int i,j;
		
		FILE *archivo = fopen("taller1Matriz.csV","w");
		
		printf("\n\n");
		fprintf(archivo,"%s","\n\n");
		
	for (i=0;i < size; i++)
	{
		printf("\n");
		for (j=0; j < size; j++)
		{	
			printf("%f2 ", matriz[i][j]);
			fprintf(archivo,"%f ",matriz[i][j]);
			
		}
	}
	
		
	
}

int main(){
	srand(time(NULL));
	int size;
	
	printf("tamaño de matriz: ");
	scanf("%d",&size);


	
	FILE *archivo;
  	archivo = fopen("taller1Matriz.csv","w");
	
	float **A= (float **)malloc(size*sizeof(float *));
	int i;
	for(i=0;i<size;i++){
		A[i]= (float *)malloc(size*sizeof(float));
	}
	
	float **B= (float **)malloc(size*sizeof(float *));
	for(i=0;i<size;i++){
		B[i]= (float *)malloc(size*sizeof(float));
	}
	
	float **C= (float **)malloc(size*sizeof(float *));
	for(i=0;i<size;i++){
		C[i]= (float *)malloc(size*sizeof(float));
	}
	
	llenarMatriz(A,size);
	llenarMatriz(B,size);
	
	//multiplicar
	for(i=0;i<size;i++){
		int j;
		for(j=0;j<size;j++){
			C[i][j]=0;
			int k;
			for(k=0;k<size;k++){
				C[i][j]=(C[i][j]+(A[i][k]*B[k][j]));
			}
		}
	}
	
 	
	imprimirMatriz(A,size);
	imprimirMatriz(B,size);
	imprimirMatriz(B,size);
	
	
	free(A); free(B); free(C);
	getch();
	
}
