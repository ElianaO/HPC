// Pi calculated with Montecarlo method.
//$ g++ -std=c++11 ompMontecarloPi.cpp -o ompMontecarloPiExe -fopenmp
//$ ./ompMontecarloPiExe

#include <iostream>
#include <time.h>
#include <cmath>
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

#define MAX_THREADS 10
#define totalpoints 10000000

 
int main() 
{ 
   //Variables  
   
   double xValue, yValue, distance;
   double start, delta;
   double pi;
   //double pointsIn;

   for (int j=1; j<= MAX_THREADS; j++) {
     // printf(" running on %d threads: ", j);
     // printf("%d\n", omp_get_thread_num()); // prueba t.e 1 

      //omp_set_num_threads(j);
      double pointsIn=0;
      int i =0;


      start = omp_get_wtime();
      #pragma omp parallel for shared(pointsIn, i) private(xValue, yValue)
      

       for(int i=0; i<totalpoints; i++) 
      { 
         //printf("%d\n", omp_get_thread_num()); // prueba t.e 2
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
      cout<<"pointsIn value: " << pointsIn <<endl;
      //printf("%d\n", omp_get_thread_num());
   
      }
   }
