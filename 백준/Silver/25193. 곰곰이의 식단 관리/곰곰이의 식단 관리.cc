#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int n;
int chicken = 0;
int others = 0;

int main() {
	cin >> n;
	string str;
	cin >> str;
	
	for(int i=0; i<str.size(); i++) {
		if(str[i] == 'C') { chicken++; }
		else { others++; }
	}
	
	if(others == 0) {
		cout << chicken;
	}
	else {
		double a = chicken;
		double b = others + 1;
		double c = ceil(a / b);
		cout << c;
	}
	
}