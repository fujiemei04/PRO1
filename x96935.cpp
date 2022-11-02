#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n,x;
    cin >> n;
    stack<int> p;
    if (n > 0) {
        cin >> x;
        p.push(x);
        bool imparell = n%2;
        int meitat = n/2;
        for (int i = 1;i < n;++i) {
            cin >> x;
            if (not imparell or i != meitat) {
                if (i >= meitat) {
                    if (p.top() == x) p.pop();
                    else i = n-1;
                }
                else p.push(x);
            }
        }
    }
    if (p.empty() or n == 1) cout << "SI" << endl;
    else cout << "NO" << endl;
}
