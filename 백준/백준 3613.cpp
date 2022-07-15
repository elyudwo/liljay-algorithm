#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <ctype.h>
using namespace std;

int main(void)
{
	string str,answer;
	cin >> str;
	int check = 0;	//check 가 1이면 c++	2면 java 
	for(int i=0; i<str.length(); i++) {
		if(str[i] == '_') {
			check = 1; 
			break;
		}
		else if(isupper(str[i])) {
			check = 2;
			break;
		}
	}
	
	if(check == 0) {
		cout << str;
	}
	else if(check == 1) {
		for(int i=0; i<str.length(); i++) {	// c++ 일때 대문자 있는지 검사 
			if(isupper(str[i])) {
				cout << "Error!";
				return 0;
			}
		}
		
		for(int i=0; i<str.length(); i++) {
			if(str[i] == '_' && str[i+1] == '_') {
				cout << "Error!";
				return 0;
			}
		}
		
		if(str[str.length()-1] == '_') {
			cout << "Error!";
			return 0;
		}
		
		if(str[0] == '_') {
			cout << "Error!";
			return 0;
		}
		
		istringstream ss(str);
		string lee;
		while(getline(ss,lee,'_')) {
			for(int i=0; i<lee.length(); i++) {
				if(i == 0) {
					char tmp = toupper(lee[i]);
					answer = answer + tmp;
				}
				else {
					answer = answer + lee[i];
				}
			}
		}
		answer[0] = tolower(answer[0]);
	}
	else if(check == 2) {
		for(int i=0; i<str.length(); i++) {
			if(str[i] == '_') {
				cout << "Error!";
				return 0;
			}
		}
		
		if(isupper(str[0])) {
			cout << "Error!";
			return 0;
		}
		answer = answer + str[0];
		for(int i=1; i<str.length(); i++) {
			if(isupper(str[i])) {
				char tmp;
				answer = answer + "_";
				tmp = tolower(str[i]);
				answer = answer + tmp;
			}
			else {
				answer = answer + str[i];
			}
		}
		
		for(int i=0; i<str.length(); i++) {
			if(isupper(str[i])) {
				str[i] = tolower(str[i]);
			}
		}
		
	}
	
	cout << answer;
	
	
	return 0;
}
