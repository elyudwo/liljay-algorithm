#include <iostream>

using namespace std;

int v[1000001];

int main() {
	int n;
	cin >> n;
	
	v[1] = 0;
	v[2] = 1;
	v[3] = 1;
	v[4] = 2;
	v[5] = 3;
	
	for(int i=6; i<=1000000; i++) {
		if(i%2 != 0 && i%3 != 0)
			v[i] = v[i-1] + 1;
		else if(i%2 == 0 && i%3 == 0) 
			v[i] = min(v[i/2] + 1,v[i/3] + 1);
		else if(i%3 == 0)
			v[i] = min(v[i/3] + 1,v[i-1] + 1);
		else if(i%2 == 0) 
			v[i] = min(v[i/2] + 1,v[i-1]+1);
		
	}
	
	cout << v[n];
	
}