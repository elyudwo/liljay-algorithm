#include <iostream>

using namespace std;

int n;

void input() {
	cin >> n;
}

int calculateSum(int x) {
	int tmp = x;
	while(x != 0) {
		tmp += x % 10;
		x /= 10;
	}
	
	return tmp;
}

void solve() {
	for(int i=1; i<=n; i++) {
		if(calculateSum(i) == n) {
			cout << i;
			return;
		}
	}
	
	cout << "0";
}

int main() {
	input();
	solve();

}