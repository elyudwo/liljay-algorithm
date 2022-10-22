#include <iostream>
#include <cmath>
using namespace std;

int main(void)
{
	int k,c;
	cin >> k;
	cin >> c;
	for(int i=0; i<c; i++) {
		int a,b;
		cin >> a >> b;
		if(a > b) {
			if(a - b <= k - a) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else if(a < b) {
			if(b - a <= k - b + 1) {
				cout << "1" << endl;
			}
			else {
				cout << "0" << endl;
			}
		}
		else {
			cout << "1" << endl;
		}
	}
	
	
	
	return 0;
}
