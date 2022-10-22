#include <iostream>

using namespace std;

int v[501][501];
long long dp[501][501];

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			cin >> v[i][j];
		}
	}
	
	dp[1][1] = v[1][1];
	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			dp[i][j] = max(dp[i-1][j] + v[i][j],dp[i-1][j-1] + v[i][j]);		
		}
	}
	
	long long result = -1;
	
	
	for(int i=1; i<=n; i++) {
		result = max(result,dp[n][i]);
	}
	cout << result;
	
	return 0;
}
