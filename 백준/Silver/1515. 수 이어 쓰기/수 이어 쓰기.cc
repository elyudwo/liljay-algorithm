#include <iostream>
#include <string>

using namespace std;
string str = "";

void input() {
	cin >> str;
}

void solve() {
	int cnt = 1;
	int idx = 0;
	
	while(1) {
		string tmp = to_string(cnt);
		for(int i=0; i<tmp.size(); i++) {
			if(tmp[i] == str[idx]) {
				idx += 1;
			}
		}
		
		if(idx == str.size()) {
			cout << cnt;
			return;
		}
		cnt += 1;
	}
}

int main() {
	input();
	solve();
	
}