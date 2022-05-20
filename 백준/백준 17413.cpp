#include <iostream>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

int main(void)
{
	string str;
	getline(cin,str);
	
	stack<char> s;
	int i = 0;
	while(str[i] != '\0') {
		if(str[i] == '<') {
			while(!s.empty()) {
				cout << s.top();
				s.pop();
			}
			while(1) {
				cout << str[i];
				if(str[i] == '>')
					break;
				i++;
			}
		}
		
		else if(isalnum(str[i])) {
			s.push(str[i]);
		}
		else {
			while(!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << " ";
		}
		i++;
	}
	
	while(!s.empty()) {
		cout << s.top();
		s.pop();
	}


	return 0;	
}
