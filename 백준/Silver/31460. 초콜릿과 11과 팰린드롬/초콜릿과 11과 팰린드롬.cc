#include <iostream>

using namespace std;

int t;

int main() {
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		if(n == 1) {
			cout << "0\n";
			continue;
		}
		cout << "1";
		for(int i=1; i<n-1; i++) {
			cout << "2";
		}
		cout << "1\n";
	}
}