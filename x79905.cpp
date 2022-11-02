#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string,int> M;
    char op;
    string s;
    while (cin >> op >> s) {
        map<string,int>::const_iterator it = M.find(s);
        if (op == 'f') {
            if (it == M.end()) cout << 0 << endl;
            else cout << it->second << endl;
        }
        else if (op == 'a') {
            if (it == M.end()) M.insert(make_pair(s,1));
            else M[s] = it->second+1;
        }
        else if (op == 'e') { 
            if (it == M.end()) M.insert(make_pair(s,0));
            else {
                if (M[s] == 0) {
                    M[s] = 0;
                }
                else M[s] = it->second-1;
            } 
        }
    }
} 