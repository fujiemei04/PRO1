#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pair {

	int value;
	int pos;
  
};

typedef vector<Pair> Com_vec;

bool comp(const Pair& a,const Pair& b) {
	
	return a.pos < b.pos; 
}

Com_vec sum(const Com_vec& v1,const Com_vec& v2) {
	
	int n1 = v1.size();
	int n2 = v2.size();
	Com_vec v(n1+n2);
	for (int i = 0;i < n1;++i) v[i] = v1[i];
	for (int i = 0;i < n2;++i) v[n1+i] = v2[i]; //concatenar
	sort(v.begin(),v.end(),comp); //ordenar
	int n = v.size();
	for (int i = 0;i < n-1;++i) {
		if (v[i].pos == v[i+1].pos) { //misma posicion?
			v[i+1].value = v[i].value+v[i+1].value; //guardar en el vector[i+1] el valor de la suma
			v[i].value = v[i].pos = 0; //vector anterior todo cero
		} 
	}
	Com_vec v3;
	for (int i = 0;i < n;++i) { 
		if (v[i].value != 0) v3.push_back(v[i]); // aÃ±adir elemento al nuevo vector si se cumple la condicion
	}
	return v3;
}
	