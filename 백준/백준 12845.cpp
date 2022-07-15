#include <iostream>
#include <algorithm>

using namespace std;

int v[1001];

bool compare(int a,int b) {
	return a > b;
}

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
		
	int sum = 0;
	
	sort(v,v+n,compare);
	
	int a = v[0];
	
	for(int i=1; i<n; i++) {
		sum = sum + v[0] + v[i];
	}
	
	cout << sum;
	
		
	return 0;
}
