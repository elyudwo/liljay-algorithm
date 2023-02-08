#include <iostream>
#include <algorithm>

using namespace std;

int v[10001];

int main(void)
{
	int k,n;
	long long sum = 0;
	cin >> k >> n;
	for(int i=0; i<k; i++) {
		cin >> v[i];
		sum = sum + v[i];
	}
	
	long long max_value = -1;
	long long l,r; 
	l = 1;
	r = sum;
	
	
	while(l <= r) {
		long long cnt = 0;
		long long mid = (l+r) / 2;
		
		for(int i=0; i<k; i++) {
			cnt = cnt + v[i]/mid;
		}
		
		
		if(cnt >= n) {
			l = mid + 1;
			max_value = max(max_value,mid);
		}
		else if(cnt < n) {
			r = mid - 1;
		}
	}
	
	cout << max_value;
	
	
	return 0;
}