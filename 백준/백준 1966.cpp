#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b) {
	return a > b;
}

int main(void)
{
	int t;
	cin >> t;
	
	for(int i=0; i<t; i++) {
		int n,m;
		cin >> n >> m;
		int v[n];
		bool c[n];
		for(int i=0; i<n; i++) {
			cin >> v[i];
		}
		
		int k = v[m];
		int cnt = 0;
		for(int i=0; i<n; i++) {
			if(k == v[i]) {
				cnt++;
			}
		}
		
		int lee = 0;
		if(cnt > 1) {
			
			for(int i=0; i<=m; i++) {
				if(v[i] >= k) {
					lee++;
				}
			}
			
			for(int i=m+1; i<n; i++) {
				if(v[i] > k) {
					lee++;
					c[i] = true;
				}
			}
			int j = 0;
			for(int i=n-1; i>m; i--) {
				if(c[i]) {
					lee = lee + j;
				}
				else {
					j++;
				}
			}
			cout << lee;
			j=0;
			for(int i=0; i<n; i++) {
				c[i] = false;
			}
		}
		
		else if (cnt <= 1) {
			sort(v,v+n,compare);
			for(int i=0; i<n; i++) {
				if(v[i] == k) {
					cout << i+1 << endl;
				}
			}
		}
		
		cnt = 0;
	}
	
	return 0;
}
