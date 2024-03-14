#include <iostream>
#include <algorithm>

using namespace std;

int t;

int main() {
	cin >> t;
	
	while(t--) {
		int a,b,c;
		cin >> a >> b >> c;
		if(a < b) {
			int tmp = a;
			a = b;
			b = tmp;
		}
		 
		if(c > a) {
			cout << "NO\n";
			continue;
		}
		int num = __gcd(a,b);
		
		if(c % num == 0 || c == a || c == b) {
			cout << "YES\n";
			continue;
		}
		cout << "NO\n";
	}
}