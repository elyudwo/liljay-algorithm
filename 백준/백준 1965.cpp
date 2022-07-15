#include <iostream>

using namespace std;

int dp[1001];
int v[1001]; 
int main(void)
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	int result = -1;
	
	for(int i=1; i<=n; i++) {
		dp[i] = 1;
	}
	 
	for(int i=1; i<=n; i++) {
		int rem = i;
		for(int j=i; j<=n; j++) {
			if(v[i] < v[j]) {
				dp[j] = max(dp[i] + 1,dp[j]);
			}
		}
	}
	
	
	int tmp = -1;
	for(int i=1; i<=n; i++) {
		if(dp[i] > tmp) {
			tmp = dp[i];
		}
	}
	
	cout << tmp;
	
	return 0;
}
