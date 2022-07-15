#include <iostream>
#include <algorithm> 
using namespace std;

int v[1000001];

bool compare(int a, int b) {
	return a > b;
}

int main(void)
{
	int n;
	cin >> n;
	int sum = 0;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	bool check = false;
	sort(v,v+n,compare);
	
	for(int i=0; i<n-2; i++) {
		if(v[i] < v[i+1] + v[i+2]) {
			sum = v[i] + v[i+1] + v[i+2];
			check = true;
			break;
		}	
	}
	
	
	if(check) {
		cout << sum;
	}
	else {
		cout << -1;
	}
	
	
	return 0;
}
