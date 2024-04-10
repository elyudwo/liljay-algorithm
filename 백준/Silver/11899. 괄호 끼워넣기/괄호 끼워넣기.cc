#include <iostream>
#include <algorithm>
 
using namespace std;


int calculateBracket(string str) {
	int f = 0, result = 0;
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '(') { f++; }
		if(str[i] == ')') {
			if(f == 0) { result++; continue; }
			f--;
		}
	}
	
	return result;
}

int main() {
	int answer = 0;
	
	string str;
	cin >> str;
	
	answer += calculateBracket(str);
	
	reverse(str.begin(), str.end());	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == '(') {
			str[i] = ')';
			continue;
		}
		str[i] = '(';
	}
	answer += calculateBracket(str);
	
	cout << answer;
}