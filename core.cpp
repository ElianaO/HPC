// Pi calculated with Montecarlo method.
//$ g++ -std=c++11 core.cpp -o coreExe -fopenmp
//$ ./coreExe

#include <iostream>
#include <time.h>
#include <cmath>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define THREAD 10
#define totalpoints 5000000// precision 

int main(int argc, char const *argv[])
{

	//Variables  
   double pi;
   double pointsIn = 0;
   double xValue, yValue, distance;
   double start, delta;


   omp_set_num_threads(THREAD);
   printf(" running on %d threads: ", THREAD);
   //printf("%d\n", omp_get_thread_num());


	start = omp_get_wtime();
	//printf("%d\n", omp_get_thread_num());
      #pragma omp parallel for private(xValue, yValue)
		
      for(int i=0; i<totalpoints; i++)
      { 
      	// printf("%d\n", omp_get_thread_num());
         xValue = (double) rand()/RAND_MAX; //Random point: x 
         yValue = (double) rand()/RAND_MAX; //Random point: y
         distance = sqrt(pow(xValue,2) + pow(yValue,2)); 
         if(distance <= 1) 
            pointsIn++; 
      } 
      delta = omp_get_wtime() - start;
      
      pi = 4 * pointsIn/totalpoints;
      cout<<"Total calculated points: "<<totalpoints<<endl;
      cout<<"Time #pragmaFor block: " << delta <<endl;
      cout<<"The value of PI is: " << pi <<endl;
      printf("%d\n", omp_get_thread_num());
	return 0;
}
