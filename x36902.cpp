#include <iostream>
#include <stack>
using namespace std;



int main() {
    stack<char> q;
    char c;
    cin >> c;
    bool is_corr = true;
    while (is_corr and c != '.') {
        if (c == '(' or c == '[') q.push(c);
        else if (c == ')') {
            if (q.empty() or q.top() != '(') is_corr = false;
            else  q.pop();
        }
        else if (c == ']') {
            if (q.empty() or q.top() != '[') is_corr = false;
            else q.pop();
        }
        cin >> c;
    }
    if (is_corr and q.empty()) cout << "Correcte" << endl;
    else cout << "Incorrecte" << endl;
}
    
