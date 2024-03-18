#include <iostream>

using namespace std;

string str;

void input() {
	cin >> str;
}

void solve() {
	int b = 0;
	int a = 1001;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == 'b') { b++; }
	}
	
	for(int i=0; i<str.size(); i++) {
		int tmp = 0;
		for(int j = i; j < i + b; j++) {
			if(str[j % str.size()] == 'a') {
				tmp++;
			}
		}
		a = min(a, tmp);
	}
	
	cout << a;
}

int main() {
	input();
	solve();
	
}