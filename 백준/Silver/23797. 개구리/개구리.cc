#include <iostream>
#include <string>
#include <stack> 

using namespace std;

string str;

void input() {
	cin >> str;
}

// KPKPKP

void solve() {
	int answer = 0;
	int k = 0, p = 0;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == 'K') {
			k++;
			if(p > 0) {
				p--;
			}
		}
		else {
			p++;
			if(k > 0) {
				k--;
			}
		}
		answer = max(answer, k+p);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
} 