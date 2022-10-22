#include <iostream>
#include <algorithm>

using namespace std;

long long dp[1001];
int v[1001]; 
int main(void)
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	dp[0] = 0;
	dp[1] = v[1];
	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			dp[i] = max(dp[i],dp[i-j] + v[j]);
		}
	}
	
	cout << dp[n];
	
	return 0;
}
