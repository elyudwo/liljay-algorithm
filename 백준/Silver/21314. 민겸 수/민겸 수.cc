#include <iostream>

using namespace std;

string str;
string large = "";
string small = "";

void input() {
	cin >> str;
}

void convertLarge() {
	int cnt = 0;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == 'K') {
			large += "5";
			for(int i=0; i<cnt; i++) {
				large += "0"; 
			}
			cnt = 0;
			continue;
		}
		cnt++;
	}
	
	if(cnt == 1) {
		large += "1";
		return;
	}
	if(cnt > 1) {
		for(int i=0; i<cnt; i++) {
			large += "1";
		}
	}
}

void convertSmall() {
	int cnt = 0;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == 'K' && !cnt) {
			small += "5";
			continue;
		}
		
		if(str[i] == 'K' && cnt) {
			small += "1";
			cnt--;
			for(int i=0; i<cnt; i++) {
				small += "0";
			}
			small += "5";
			cnt = 0;
			continue;
		}
		
		cnt++;
	}
	
	if(cnt == 1) {
		small += "1";
		return;
	}
	if(cnt > 1) {
		small += "1";
		for(int i=0; i<cnt-1; i++) {
			small += "0";
		}
	}
}

void solve() {
	convertLarge();
	convertSmall();
	
	cout << large << '\n' << small;
}

int main() {
	input();
	solve();
	
}