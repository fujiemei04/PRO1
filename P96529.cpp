#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string word;
    while (cin >> word) {
        vector<char> v(0);
        bool match = true;
        int i = 0;
        while (match and i < word.size()) {
            char c = word[i];
            if (c == '(' or c == '[') {
                v.push_back(c);
            }
            else {
                if (v.size() > 0) {
                    char x = v[v.size() - 1];
                    if ((c == ')' and x == '(') or (c == ']' and x == '[')) {
                        v.pop_back();
                    }
                    else {
                        match = false;
                    }
                }
                else {
                    match = false;
                }
            }
            i++;
        }
        if (match and v.size() == 0) {
            cout << "si" << endl;
        } else {
            cout << "no" << endl;
        }
    }
}