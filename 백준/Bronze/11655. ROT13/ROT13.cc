#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string ROT13(string str) {
	for(int i=0; i<str.size(); i++) {
		if(str[i] >= 'a' && str[i] <= 'z') {
			int tmp = str[i] - 'a';
			if(tmp < 13) {
				tmp = tmp + 13;
			}
			else {
				tmp = tmp - 13;
			}
			str[i] = tmp + 'a';
			continue;
		}
		if(str[i] >= 'A' && str[i] <= 'Z') {
			int tmp = str[i] - 'A';
			if(tmp < 13) {
				tmp = tmp + 13;
			}
			else {
				tmp = tmp - 13;
			}
			str[i] = tmp + 'A';
			continue;
		}
	}
	return str;
}

int main() {
	string str;
	getline(cin, str);
	
	cout << ROT13(str);
}