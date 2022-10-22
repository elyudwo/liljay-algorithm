#include <iostream>
#include <algorithm>

using namespace std;

int v[1001][3];

long long dp[1001][3];

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<3; j++) {
			cin >> v[i][j];
		}
	}
	
	dp[0][0] = v[0][0];
	dp[0][1] = v[0][1];
	dp[0][2] = v[0][2];
	
	for(int i=1; i<n; i++) {
		for(int j=0; j<3; j++) {
			if(j == 1) {
				dp[i][j] = min(dp[i-1][0] + v[i][j] , dp[i-1][2] + v[i][j]);
			}
			else if(j == 0) {
				dp[i][j] = min(dp[i-1][1] + v[i][j] , dp[i-1][2] + v[i][j]);
			}
			else if(j == 2) {
				dp[i][j] = min(dp[i-1][1] + v[i][j] , dp[i-1][0] + v[i][j]);
			}
		}
	}
	
	long long result = 999999999;
	
	for(int i=0; i<3; i++) {
		result = min(result,dp[n-1][i]);
	}
	cout << result;
	
	
	return 0;
}
