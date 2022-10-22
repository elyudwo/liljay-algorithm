#include <iostream>
#include <algorithm>
using namespace std;

int v[250001];

int main(void)
{
	int n,m;
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	long long sum = 0;
	int cnt = 0;
	for(int i=0; i<m; i++) {
		sum = sum + v[i];
	}
	
	long long max_value = sum;

	for(int i=m; i<=n-1; i++) {
		sum = sum + v[i] - v[i-m] ;
		if(max_value < sum) {
			max_value = sum;
		} 
	}

	if(max_value == 0) {
		cout << "SAD";
		return 0;
	}
	else {
		sum = 0;
		for(int i=0; i<m; i++) {
			sum = sum + v[i];
		}
		if(sum == max_value) {
			cnt++;
		}
		for(int i=m; i<=n; i++) {
			sum = sum - v[i-m] + v[i];
			if(sum == max_value) {
				cnt++;
			} 
		}
	}
	cout << max_value << endl << cnt;
	
	return 0;
}
