#include <iostream>

using namespace std;

int v_ulim[10];
int v_start[10];

int main(void)
{
	int a = 0;
	int b = 0; 
	for(int i=1; i<=9; i++) {
		cin >> v_ulim[i];
	}
	for(int i=1; i<=9; i++) {
		cin >> v_start[i];
	}
	
	bool check = false;
	
	for(int i=1; i<=9; i++) {
		a = a + v_ulim[i];
		if(a > b) {
			check = true;
			break;
		}
		b = b + v_start[i];
		if(a > b) {
			check = true;
			break;
		}
		
	}
	
	if(check) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
		
	
	return 0;
}
