#include <iostream>
#include <algorithm>
using namespace std;

long long v[200001];
long long lee[200001];

bool compare(int a,int b) {
	return a > b;
}

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	long long sum = 0;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	for(int i=0; i<m; i++) {
		cin >> lee[i];
	}
	

	sort(v,v+n,compare);
	sort(lee,lee+m);
	
	for(int i=0; i<m; i++) {
		if(lee[i] < v[i]) {
			sum = sum + v[i] - lee[i];
		}
	}
	
	
	cout << sum;
	
	return 0;
}
