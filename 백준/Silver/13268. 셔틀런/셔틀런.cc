#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int time = 0;
	
	
	n = n % 100;
	if((n > 0 && n <= 9) || (n>=11 && n<=15) || (n>=25 && n<=29) || (n>=31 && n<=35) || (n>=55 && n<=59) || 
	(n>=61 && n<=65) || (n>=95 && n<=99) ) {
		cout << "1";
	}
	else if((n>=16 && n<=24) || (n>=36 && n<=40) || (n>=50 && n<=54) || (n>=66 && n<=70) || (n>=90 && n<=94)) {
		cout << "2";
	}
	else if((n>=41 && n<=49) || (n>=71 && n<=75) || (n>=85 && n<=89)) {
		cout << "3";
	}
	else if((n>=76 && n<=84)) {
		cout << "4";
	}
	else {
		cout << "0";
	}
	
	
}