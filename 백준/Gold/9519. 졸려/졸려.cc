#include <iostream>
#include <vector>

using namespace std;

int n;
string str;
int s;

void input() {
	cin >> n;
	cin >> str;
	s = str.size();
}

void evenCheck() {
	string str_rem = str;
	int cnt = 0;
	
	while(1) {
		string tmp = "";
		tmp += str_rem[0];
		
		for(int i=2; i<s; i = i + 2) {
			tmp += str_rem[i];
		}
		for(int i=s-1; i>=0; i = i - 2) {
			tmp += str_rem[i];
		}
		cnt += 1;
		str_rem = tmp;
		
		if(tmp == str) {
			n = n % cnt;
			break;
		}
	}
	
	for(int i=0; i<n; i++) {
		string tmp = "";
		tmp += str_rem[0];
		
		for(int i=2; i<s; i = i + 2) {
			tmp += str_rem[i];
		}
		for(int i=s-1; i>=0; i = i - 2) {
			tmp += str_rem[i];
		}
		cnt += 1;
		str_rem = tmp;
	}
	
	cout << str_rem;
}

/*
sarma
saamr 
*/
void oddCheck() {
	string str_rem = str;
	int cnt = 0;
	
	while(1) {
		string tmp = "";
		tmp += str_rem[0];
		
		for(int i=2; i<s; i = i + 2) {
			tmp += str_rem[i];
		}
		for(int i=s-2; i>=0; i = i - 2) {
			tmp += str_rem[i];
		}
		cnt += 1;
		str_rem = tmp;
		if(tmp == str) {
			n = n % cnt;
			break;
		}
	}
	
	for(int i=0; i<n; i++) {
		string tmp = "";
		tmp += str_rem[0];
		
		for(int i=2; i<s; i = i + 2) {
			tmp += str_rem[i];
		}
		for(int i=s-2; i>=0; i = i - 2) {
			tmp += str_rem[i];
		}
		cnt += 1;
		str_rem = tmp;
	}
	
	cout << str_rem;
}

void solve() {
	if(s % 2 == 0) {
		evenCheck();
	}
	else {
		oddCheck();
	}
}

int main() {
	input();
	solve();
	
}