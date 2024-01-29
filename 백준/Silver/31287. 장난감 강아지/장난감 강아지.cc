#include <iostream>

using namespace std;

int n, k;
string str;

void input() {
	cin >> n >> k;
	cin >> str;
}

void solve() {
	int x = 0, y = 0;
	
	for(int i=0; i<str.size() * (k % 2001); i++) {
		if(str[i % str.size()] == 'U') { y += 1; }
		if(str[i % str.size()] == 'D') { y -= 1; }
		if(str[i % str.size()] == 'R') { x += 1; }
		if(str[i % str.size()] == 'L') { x -= 1; }
		
		if(x == 0 && y == 0) {
			cout << "YES";
			return;
		}
	}
	cout << "NO";
}

int main() {
	input();
	solve();
	
}