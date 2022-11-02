#include <iostream>
using namespace std;

double factorial(int n) {

 double product = 1;
 for (int i = 1;i <= n;++i) {
	 product = product*i;
 }
 return product;
}

double eaprox(int n) { 
	
  double e = 0;
  if (n == 0) return e;
  for (int i = 0;i < n;++i) {
	  e = e + 1.0/factorial(i);
  }
  return e;
}

int main() {
  
  cout.setf(ios::fixed);
  cout.precision(10);
  int n;
  while (cin >> n) {
  cout << "With " <<  n << " term(s) we get " << eaprox(n) << "."<< endl;
  }
}