#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(void)
{
	int v[4];
	int lee[4];
	for(int i=0; i<4; i++) {
		v[i] = i+1;
	}
	lee[0] = 1;
	lee[1] = 2;
	lee[2] = 4;
	lee[3] = 3;
	
	/* 
	do {
		for(int i=0; i<4; i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}while(next_permutation(v,v+4));
	*/
	
	if(next_combination(lee,lee+4)) {
		for(int i=0; i<4; i++) {
			cout << lee[i] << " ";
		}
	}
	
	return 0;
}
