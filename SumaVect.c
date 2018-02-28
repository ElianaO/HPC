#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float *SumVect(float *vec1, float *vec2, int size)
{
	FILE *f = fopen("taller1Vector.csv", "w");
	float *result = malloc(sizeof(float) * size);
	int i;
	for (i=0; i < size; i++){
		result[i] = vec1[i] + vec2[i];
		printf("Vec Resultado Posicion %d %2.2f\n",i,result[i]);
		fprintf(f, "%f,", result[i]);
	}
	fclose(f);
	free(result);	
	return result;
}

void llenarVect(float *vec, int size){
	int i;
//
	for (i=0; i < size; i++){
		vec[i] =  (float)(rand() / 11.0);
		printf("posicion %d %2.2f\n",i,vec[i]); 
	}
	printf("\n");
}


int main()
{
	srand(time(NULL));

	int size;
	printf("Vector size: ");
	scanf("%d", &size);

	float *vect1 = malloc(sizeof(float) * size);
	llenarVect(vect1, size);

	float *vect2 = malloc(sizeof(float) * size);
	llenarVect(vect2, size);

	float *result = SumVect(vect1, vect2, size);
	
//	free(result);

//	return 0;
getch();
}
