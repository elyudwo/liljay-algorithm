#include <iostream>

using namespace std;

int now;
int tmp = 0;
bool c = true;
int lee = 0;
string str;

void checkCaseOne() {
	// 1 번 케이스 && 사이즈 안맞을 때
	if(tmp > str.size() - 4) {
		c = false;
		lee = 100;
		return;
	}
	
	// 10011001
	
	tmp += 1;
	if(!(str[tmp] == '0' && str[tmp+1] == '0')) {
		c = false;
		lee = 100;
		return;
	}
	
	tmp += 2;
	
	while(1) {
		if(tmp == str.size()) {
			c = false;
			lee = 100;
			return;
		}
		
		if(str[tmp] == '1') {
			tmp += 1;
			break;
		}
		else { tmp += 1; }
	}
	
	int cnt = 0;
	
	while(tmp < str.size()) {
		if(str[tmp] == '0' && str[tmp+1] == '0' && cnt != 0) {
			tmp -= 1;
			break;
		}
		else if(str[tmp] == '0') {
			break;
		}
		else {
			tmp += 1;
		}
		cnt += 1;
	}
	
}

void checkCaseZero() {
	if(tmp >= str.size()-1) {
		c = false;
		lee = 100;
		return;
	}
	
	while(tmp < str.size()) {
		if(str[tmp] == '0' && str[tmp+1] == '1') {
			tmp += 2;
		}
		else if(str[tmp] == '0' && str[tmp+1] == '0') {
			c = false;
			lee = 100;
			return;
		}
		else { break; }
	}
}

void check() {
	while(1) {
		if(tmp >= str.size()) {
			break;
		}
		
		if(str[tmp] == '1') { checkCaseOne(); }
		else if(str[tmp] == '0') { checkCaseZero(); }
		
		if(lee == 100) {
			break;
		}
	}
	
}

// 10010

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		cin >> str;
		if(str[0] == '1') { now = 1; }
		else { now = 0; }
		check();
		
		if(c) { cout << "YES" << '\n'; }
		else { cout << "NO" << '\n'; }
		
		tmp = 0;
		lee = 0;
		c = true;
		
	}
}