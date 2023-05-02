#include <iostream>
#include <map>
#include <queue>

using namespace std;

int T;
long long word,s,t;

void solve() {
	long long answer = 0;
	
	while(word != 0) {
		if(word % 2 == 1) {
			word = word - 1;
			answer += s;
		}
		else {
			if(word/2 > t) { answer += t; }
			else {
				if(word/2 *s > t) {
					answer += t;
				}
				else {
					answer += s * word/2; 
				}
			}
			word = word/2;
		}
	}
	
	cout << answer << '\n';
}

void input() {
	cin >> T;
	
	while(T--) {
		cin >> word;
		cin >> s >> t;
		solve();
	}
}

int main() {
	input();
}