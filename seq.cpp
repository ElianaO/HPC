// Pi calculated with Montecarlo method.
//$ g++ -std=c++11 seq.cpp -o seqExe
//$ ./seqExe


#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <cmath>

using namespace std;

 
int main() 
{
   long totalpoints = 100000000;    // puntos a evaluar (precisión)
   double pi;                       // valor de Pi
   double pointsIn = 0;             // valores que cumplen la condicion x<=1
   double xValue, yValue, distance; // a, b, hipotenusa
   double start, delta;             // calculo del tiempo

   start = clock();
   for(int i=0; i<totalpoints; i++)
   { 
      xValue = (double) rand()/RAND_MAX; //Random point: x 
      yValue = (double) rand()/RAND_MAX; //Random point: y
      distance = (xValue * xValue) + (yValue * yValue); // |
      distance = sqrt(distance);                        // | hipotenusa = distancia
      if(distance <= 1) 
         pointsIn++; 
   }
   delta = double(clock()-start)/CLOCKS_PER_SEC;
   
   pi = 4 * pointsIn/totalpoints;
   cout<<"Calculated points: "<<totalpoints<<endl;
   cout<<"Time For{}: "<<delta<<endl;
   cout<<"The vaule of PI is: " << pi <<endl;
   return 0; 
}
