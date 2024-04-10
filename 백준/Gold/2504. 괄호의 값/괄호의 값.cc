#include <iostream>
#include <stack>
#include <string>

using namespace std;

string str;

void input() {
	cin >> str;
}

bool can() {
	stack<char> stk;
	for(char c : str) {
		if(c == ')') {
			if(stk.empty() || stk.top() != '(') { return false; }
			stk.pop();
			continue;
		}
		if(c == ']') {
			if(stk.empty() || stk.top() != '[') { return false; }
			stk.pop();
			continue;
		}
		stk.push(c);
	}
	
	return true;
}

void solve() {
    int answer = 0;
	if(!can()) {
		cout << "0";
		return;
	}
	stack<string> stk;
	
	for(char c : str) {
		if(c == '(' || c == '[') {
            string s = "";
            s += c;
			stk.push(s);
			continue;
		}
		if(c == ')') {
			int tmp = 0;
			while(1) {
				if(stk.top() != "(") {
					tmp += stoi(stk.top());
					stk.pop();
					continue;
				}
				stk.pop();
				tmp = tmp * 2;
				if(tmp == 0) tmp = 2;
				stk.push(to_string(tmp));
				break;
			}
		}
		if(c == ']') {
			int tmp = 0;
			while(1) {
				if(stk.top() != "[") {
					tmp += stoi(stk.top());
					stk.pop();
					continue;
				}
				stk.pop();
				tmp = tmp * 3;
				if(tmp == 0) tmp = 3;
				stk.push(to_string(tmp));
				break;
			}
		}
	}
	
	while(!stk.empty()) {
	    if(stk.top() == "(" || stk.top() == ")" || stk.top() == "[" || stk.top() == "]") {
	        cout << "0";
	        return;
	    }
	    answer += stoi(stk.top());
	    stk.pop();
	}
	
	cout << answer;
	
}

int main() {
	input();
	solve();
}