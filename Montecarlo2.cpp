// Pi calculated with Montecarlo method.
//$ g++ -std=c++11 Montecarlo2.cpp -o Montecarlo2Exe -fopenmp
//$ ./Montecarlo2Exe

#include <stdlib.h>
#include <stdio.h>
#include <omp.h>

int main()
{
	int count;
	int i;
	int local_count;
	int samples;
	int t;
	int tid;
	double x,y;
	unsigned short xi[3];
	double start, delta;
	
	samples= 100000000;
	
	count=0;
	
	{
	local_count=0;
	


	t = omp_get_num_threads();
	
	printf("El Numero de hilos es: %d \n",t );
	start = omp_get_wtime();
	for (i=tid; i<samples; i += t){
		
		x=(double) rand()/RAND_MAX; //Random point: x
		y=(double) rand()/RAND_MAX; //Random point: y

		if(x*x + y*y <= 1.0) 
			local_count +=1;
	}
	//printf("%d\n", omp_get_thread_num());

	#pragma omp critical
	//printf("%d\n", omp_get_thread_num());
	count += local_count;
	delta = omp_get_wtime() - start;
	}

	printf("Valor estimado de Pi: %7.5f\n",4.0*count/samples);
	printf("Tiempo del #Pragma por bloque: %7.5f\n",delta);
	printf("Total puntos calculados: %d \n ", samples);
	printf("%d\n", omp_get_thread_num());
}
