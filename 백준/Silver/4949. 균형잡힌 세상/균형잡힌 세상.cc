#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkStr(string str) {
	stack<char> stk;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '(' || str[i] == '[') { stk.push(str[i]); }
		else if(str[i] == ')') {
			if(stk.size() == 0) { return false; }
			if(stk.top() != '(') { return false; }
			if(stk.top() == '(') {
				stk.pop();
			}
		}
		else if(str[i] == ']') {
			if(stk.size() == 0) { return false; }
			if(stk.top() != '[') { return false; }
			if(stk.top() == '[') {
				stk.pop();
			}
		}
	}
	
	if(stk.size() != 0) {
		return false;
	}
	return true;
}

void solve() {
	while(1) {
		string str;
		getline(cin,str);
		if(str == ".") { break; }
		
		if(checkStr(str)) { cout << "yes" << '\n'; }
		else { cout << "no" << '\n'; }
	}
}

int main() {
	solve();
}