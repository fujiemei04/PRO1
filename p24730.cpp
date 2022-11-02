#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Parv{
   string name;
   int carrot,sweet;
};

bool comp(const Parv& a,const Parv& b) {
    if (a.name.size() == b.name.size() and a.carrot == b.carrot and a.sweet == b.sweet) return a.name < b.name;
    if (a.carrot == b.carrot and a.sweet == b.sweet) return a.name.size() < b.name.size();
    if (a.sweet == b.sweet) return a.carrot > b.carrot;
    return a.sweet > b.sweet;
}

vector<Parv> p(int n) {
    vector<Parv> v(n);
    for (int i = 0;i < n;++i) cin >> v[i].name >> v[i].sweet >> v[i].carrot;
    return v;
}

int main() {
   
   int n;
   cin >> n;
   for (int i = 0;i < n;++i) {
       int m;
       cin >> m;
       vector<Parv> v = p(m);
       sort(v.begin(),v.end(),comp);
       for (int j = 0;j < m;++j) cout << v[j].name << endl;
       cout << endl;
    }
}