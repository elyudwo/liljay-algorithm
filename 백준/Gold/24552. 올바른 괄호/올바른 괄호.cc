#include <iostream>
#include <algorithm>

using namespace std;

string str;

void input() {
	cin >> str;
}

void solve() {
	int open = 0, close = 0, answer = 0;
	
	for(char c : str) {
		if(c == '(') {
			open++;
			continue;
		}
		close++;
	}
	
	if(open > close) {
	    reverse(str.begin(), str.end()); 
	    for(int i=0; i<str.size(); i++) {
    	    if(str[i] == '(') {
    	        str[i] = ')';
    	        continue;
    	    }
    	    str[i] = '(';
    	}
	}

	int now_open = 0, now_close = 0;
	
	
	
	
	for(char c : str) {
		if(c == '(') { now_open++;}
		else { now_close++; }
		
		if(now_close > now_open) {
			cout << now_close;
			return;
		}
	}
}

int main() {
	input();
	solve();
	
}