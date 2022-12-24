#include <iostream>
#include <stack>
#include <string>
#include <cmath>
using namespace std;

stack<char> stk;
int result = 0;
bool check = true;

void printStack(stack<char> tmp) {
	int s = tmp.size(); 
	for(int i=0; i<s; i++) {
		cout << tmp.top();
		tmp.pop();
	}
	cout << endl;
}

void calculate(char c) {
	stk.pop();
	stack<char> rem = stk;
	
	int tmp = 0;
	int one = 0;
	int two = 0;
	int s = rem.size();
	for(int i=0; i<s; i++) {
		if(rem.top() == '(') {
			one++;
		}
		else if(rem.top() == '[') {
			two++;
		}
		rem.pop();
	}
	
	if(one != 0) {
		tmp = pow(2,one);
	}
	if(two != 0) {
		tmp = pow(3,two);
	}
	
	if(c == ']') {
		result = result + tmp*3;
	}
	else if(c == ')'){
		result = result + tmp*2;
	}
}


int main() {
	string str;
	cin >> str;
	for(int i=0; i<str.length(); i++) {
		if(str[i] == ')') {
			if(stk.top() != '(') {
				check = false;
				break;
			}
			calculate(')');
		}
		else if(str[i] == ']') {
			if(stk.top() != '[') {
				check = false;
				break;
			}
			calculate(']');
		}
		else {
			stk.push(str[i]);
		}
		printStack(stk);
	}	
	
	if(!check) {
		cout << "0";
	}
	else {
		cout << result;
	}
	
}
