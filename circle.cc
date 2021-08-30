#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <math.h>

using namespace std;

int main () {
     double area, xin, yin, xout, yout, hit;
	 int ntrials; 
	 cout << "enter n:" << endl;
	 cin >> ntrials;
     srand48(time(NULL));

	 for(int i = 0; i < 10; i++) { 
    	printf("Random number #%d: %f\n", i, drand48());
	 }
     
	 bool in;
     ofstream out("circle.dat");
     for (int i = 0; i < ntrials; i++) {
         double x = 2*(drand48()-.5);
         double y = 2*(drand48()-.5);
         double r = sqrt(x*x + y*y);
         if (r < 1.0) {
             //xin = x;
             //yin = y;
             hit += 1;
			 in = true;
         } else {
             //xout = x;
             //yout = y;
			 in = false;
         }
         //out << xin << " " << yin << " " << xout << " " << yout << endl;
         out << x << " " << y << " " << in << endl;
     }
     out.close();
     area = 4 * (hit / ntrials);
     cout << "Area: " << area << endl;
     cout << "Actual area: " << M_PI << endl;
     cout << "Error: " << "% " << (fabs( M_PI - area)/M_PI)*100. << endl;
}
