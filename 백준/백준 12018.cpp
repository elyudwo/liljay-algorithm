#include <iostream>
#include <algorithm>

using namespace std;

int sum[101];
int v[101];

bool compare(int a,int b) {
	return a > b;
}

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		int a,b;
		cin >> a >> b;
		
		for(int j=0; j<a; j++) {
			cin >> v[j];		
		}
		
		sort(v,v+a,compare);
		
		if(v[b-1] == 0) {
			sum[i] = 1;
		}
		else {
			sum[i] = v[b-1];
		}
	

		for(int i=0; i<101; i++) {
			v[i] = 0;
		}
	}
	
	sort(sum,sum+n);
	
	int cnt = 0;
	int lee = m;
	for(int i=0; i<n; i++) {
		if(lee - sum[i] > 0) {
			cnt++;
			lee = lee - sum[i];
		}
		else {
			break;
		}
	}
	
	cout << cnt;
	
	return 0;
}
