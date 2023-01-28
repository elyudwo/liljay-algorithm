#include <iostream>
#include <stack>
using namespace std;

stack<string> stk;
string str;


void input() {
	cin >> str;
}

void multi(char c) {
	string tmp = stk.top();
	stk.pop();
	int rem = stoi(tmp) * (c-'0');
	stk.push(to_string(rem));
}

void calPlus() {
	int sum = 0;
	while(1) {
		if(stk.top() == "(") {
			stk.pop();
			stk.push(to_string(sum));
			break;
		}
		string tmp = stk.top();
		stk.pop();
		int rem = stoi(tmp);
		sum += rem;
	}
}

void solve() {
	int answer = 0;
	
	for(int i=0; i<str.length(); i++) {
	    
		if(isdigit(str[i])) { multi(str[i]); }
		if(str[i] == ')') { calPlus(); }
		if(str[i] == 'H') { stk.push("1"); }
		if(str[i] == 'C') { stk.push("12"); }
		if(str[i] == 'O') { stk.push("16"); }
		if(str[i] == '(') { stk.push("("); }
	}
	
	while(!stk.empty()) {
		string tmp = stk.top();
		stk.pop();
		answer += stoi(tmp);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}