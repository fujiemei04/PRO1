#include <iostream>
#include <set>
using namespace std;

int main() {
    string p;
    set<string> totes,cap,falta;
    cin >> p;
    while (p != ".") {
        totes.insert(p);
        cin >> p;
    }
    cap = totes;
    int n;
    cin >> n;
    for (int i = 0;i < n;++i) {
        falta = totes;
        cin >> p;
        while (p != ".") {
           cap.erase(p);
           falta.erase(p);
           cin >> p;
        }
        for (set<string>::iterator it = falta.begin();it != falta.end();++it) totes.erase(*it);
    }
    cout << "Totes les activitats:";
    for (set<string>::iterator it = totes.begin();it != totes.end();++it) cout << " " << *it;
    cout << endl;
    cout << "Cap activitat:" ;
    for (set<string>::iterator it = cap.begin();it != cap.end();++it) cout << " " << *it;
    cout << endl;
} 