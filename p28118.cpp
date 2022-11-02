   
#include <iostream>
#include <cmath>
using namespace std;

double distance(double x1,double y1,double x2,double y2) {

  return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

int main() {
  cout.setf(ios::fixed);
  cout.precision(4);

  string c;
  double x1,y1,x2,y2;
  while (cin >> c) {
    double total = 0;
    cin >> x1 >> y1;
	double xorig = x1;
	double yorig = y1;
	bool stop = true;
	while (stop and cin >> x2 >> y2) {
	  total = total + distance(x1,y1,x2,y2);
	  if (x2 == xorig and y2 == yorig) stop = false;
	  else {
	    x1 = double(x2);
	    y1 = double(y2);
      }
	}
	cout << "Route "<< c << ": " << total << endl;
  }
  
  
}