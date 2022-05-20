#include <iostream>

using namespace std;

int main(void)
{
	int x,y;
	cin >> x >> y;
	
	int sum = 0;
	if(x == 1) {
		sum = sum + 0;
	}
	else if(x == 2) {
		sum = sum + 31;
	}
	else if(x == 3) {
		sum = sum + 31 + 28;
	}
	else if(x == 4) {
		sum = sum + 31 + 28 + 31;
	}
	else if(x == 5) {
		sum = sum + 31 + 28 + 31 + 30;
	}
	else if(x == 6) {
		sum = sum + 31 + 28 + 31 + 30 + 31;
	}
	else if(x == 7) {
		sum = sum + 31 + 28 + 31 + 30 + 31 + 30;
	}
	else if(x == 8) {
		sum = sum + 31 + 28 + 31 + 30 + 31 + 30 + 31;
	}
	else if(x == 9) {
		sum = sum + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31;
	}
	else if(x == 10) {
		sum = sum + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30;
	}
	else if(x == 11) {
		sum = sum + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31;
	}
	else if(x == 12) {
		sum = sum + 31 + 28 + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30;
	}
	
	sum = (sum + y) % 7;
	
	if(sum == 0) {
		cout << "SUN";
	}
	else if(sum == 1) {
		cout << "MON";
	}
	else if(sum == 2) {
		cout << "TUE";
	}
	else if(sum == 3) {
		cout << "WED";
	}
	else if(sum == 4) {
		cout << "THU";
	}
	else if(sum == 5) {
		cout << "FRI";
	}
	else if(sum == 6) {
		cout << "SAT";
	}
	
	
	
	return 0;
}
