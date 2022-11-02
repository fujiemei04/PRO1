#include <iostream>
using namespace std;

bool is_primer(int n) {
    
    int divisor = 2;
    bool is_prime = (n != 1);
    while (is_prime and divisor*divisor <= n) { 
	  is_prime = n%divisor != 0;
      divisor = divisor + 1;
    }
return is_prime;
}

bool is_perfect_prime(int n) {
	if (n == 0) return false;
	else if (not is_primer(n)) return false;
	int sum = 0;
	int digits = 0;
	while (n > 0) {
		sum = sum+n%10;
		n = n/10;
		++digits;
	}
	bool resultat_primer = is_primer(sum);
	if (resultat_primer and digits == 1) return true;
	else if (resultat_primer) return is_perfect_prime(sum);
	else return false;
		
	} 

int main() {
	
	int n;
	while (cin >> n) {
	if (is_perfect_prime(n)) cout << "true"<< endl;
	else cout <<  "false" << endl;
    }
}