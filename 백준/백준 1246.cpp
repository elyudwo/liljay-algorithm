#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int v[1001];

bool compare(int a, int b) {
	return a > b;
}

int main(void)
{
	int n,m;
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		cin >> v[i];
	}	
	
	sort(v,v+m,compare);
	int max_sum = -1;
	int result;
	
	for(int i=v[0]; i>=v[n-1]; i--) {
		int sum = 0;
		for(int j=0; j<m; j++) {
			if(v[j] >= i) {
				sum = sum + i;
			}	
		}
		
		if(max_sum < sum) {
			max_sum = sum;
			result = i;
		}
		
	}
	
	cout << result << " " << max_sum;
	
	return 0;
}
