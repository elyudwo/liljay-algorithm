#include <iostream>
#include <set>

using namespace std;

int n;
char game;
set<string> s;

void input() {
	cin >> n >> game;
	for(int i=0; i<n; i++) {
		string str;
		cin >> str;
		s.insert(str);
	}
}

void solve() {
	if(game == 'Y') {
		cout << s.size();
	}
	else if(game == 'F') {
		cout << s.size()/2;
	}
	else {
		cout << s.size()/3;
	}
}

int main() {
	input();
	solve();
}
