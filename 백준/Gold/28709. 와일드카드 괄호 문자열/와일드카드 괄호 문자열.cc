#include <iostream>
#include <algorithm>

using namespace std;

int t;

bool frontCheck(string str) {
	int f = 0, b = 0;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '(' || str[i] == '?') { f++; }
		if(str[i] == ')') { b++; }
		
		if(b > f) { return false; }
		
		if(str[i] == '*') { break; }
	}
	
	return true;
}

bool backCheck(string str) {
	reverse(str.begin(), str.end());
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '(') { str[i] = ')'; continue;}
		if(str[i] == ')') { str[i] = '('; }
	}
	int f = 0, b = 0;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '(' || str[i] == '?') { f++; }
		if(str[i] == ')') { b++; }
		
		if(b > f) { return false; }
		
		if(str[i] == '*') { break; }
	}
	
	return true;
}

bool oddCheck(string str) {
	int cnt = 0;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '*') {
			return false;
		}
		cnt++;
	}
	
	if(cnt % 2 == 1) {
		return true;
	}
	return false;
}

int main() {
	cin >> t;
	
	while(t--) {
		string str;
		cin >> str;
		bool check = true;
		
		if(oddCheck(str)) {
			cout << "NO\n";
			continue;
		}
		
		if(!frontCheck(str)) {
			cout << "NO\n";
			continue;
		}
		if(!backCheck(str)) {
			cout << "NO\n";
			continue;
		}
		
		cout << "YES\n";
	}
}