#include <iostream>
#include <vector>
using namespace std;

struct Punto {

  double x,y;

};

bool prop1(const vector<Punto>& v) {
	
	int n = v.size();
	int count = 0;
	for (int i = 0;i < n-1;++i) {
		if (v[i].x != v[i+1].x or v[i].y != v[i+1].y) ++count;
	}
	if (count > 1) return true;
	else return false;
	
}
bool prop2(const vector<Punto>& v) {
  
	Punto p;
	p.x = 0;
	p.y = 0;
  int n = v.size();
  for (int i = 0;i < n;++i) {
	  p.x = p.x + v[i].x;
	  p.y = p.y + v[i].y;
  }	
  if (p.x == p.y) return true;
  else return false;
	
}


bool baricentro(const vector<Punto>& v, Punto& b) {
	
	int n = v.size();
	for (int i = 0; i < n;++i) {
		if (v[i].x == b.x and v[i].y == b.y) return false;
	}
	return true;
}

int main() {
	
	cout.setf(ios::fixed);
	cout.precision(2);
	int n;
	while (cin >> n) {
	  vector <Punto> v(n);
	  Punto b;
	  b.x = b.y = 0;
	  for (int i = 0;i < n;++i) {
		  cin >> v[i].x >> v[i].y;
		  b.x = b.x + v[i].x;
		  b.y = b.y + v[i].y;
	  }
	  Punto b1;
	  b1.x = b.x/n;
	  b1.y = b.y/n;
	  cout << "baricentro: (" << b1.x << "," << b1.y << ")" << endl;
	  if (not prop1(v)) cout << "el vector no cumple la propiedad 1" << endl;
      else if (not prop2(v)) cout << "el vector no cumple la propiedad 2" << endl;
      else if (not baricentro(v,b1)) cout << "el vector no cumple la propiedad 3" << endl;
	  else cout << "vector normalizado" << endl;
	 }
}
