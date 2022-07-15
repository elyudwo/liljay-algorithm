#include <iostream>
#include <algorithm>
using namespace std;

int v[101];

int main(void)
{
	int n,k,a,b;
	cin >> n >> k >> a >> b;
	
	for(int i=0; i<n; i++) {
		v[i] = k;
	}
	int day = 0;
	while(1) {
		sort(v,v+n);
		if(v[0] == 0) {
			cout << day;
			break;
		}
		
		for(int i=0; i<a; i++) {
			v[i] = v[i] + b;
		}
		for(int i=0; i<n; i++) {
			v[i] = v[i] - 1;
		}
		day++;
		
	}
	
	return 0;
}
