#include <iostream>
#include <algorithm>
using namespace std;

int v[10001];

int result[5001];

bool compare(int a,int b) {
	return a > b;
}

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=0; i<2*n; i++) {
		cin >> v[i];
	}
	
	sort(v,v+n*2,compare);
	
	
	
	for(int i=0; i<n; i++) {
		result[i] = v[i] + v[2*n-(i+1)];
	}
	
	sort(result,result+n);
	
	cout << result[0];
	
	return 0;
}
