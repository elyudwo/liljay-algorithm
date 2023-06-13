#include <iostream>
#include <string>

using namespace std;

int n;
string str = "";
string alp = "BCDEFGHIJKLMNOPQRSTUVWXY";

int main() {
	cin >> n;
	if(n == 0) {
		cout << "GBSISTHEBEST";
		return 0;
	}
	
	while(n) {
		int tmp;
		
		for(int i=1; i<=100000; i++) {
			if(n < i * i) { tmp = i-1; break;}
		}
		
		for(int i=0; i<tmp; i++) { str += 'A'; }
		
		str += alp;
		
		for(int i=0; i<tmp; i++) { str += 'Z'; }
		
		n = n - tmp * tmp;
	}
	
	cout << str;
}