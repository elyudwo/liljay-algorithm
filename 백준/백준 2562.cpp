#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n[9];
	for(int i=0; i<9; i++) {
		cin >> n[i];
	}
	
	int max_tmp = -1;
	
	for(int i=0; i<9; i++) {
		max_tmp = max(max_tmp,n[i]);
	}
	
	for(int i=0; i<9; i++) {
		if(n[i] == max_tmp) {
			cout << max_tmp << endl;
			cout << i+1;
			break;
		}
	}
	
	
	return 0;
}
