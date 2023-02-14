#include <iostream>

using namespace std;

long long dp[201][201];

int main() {
	int n,k;
	cin >> n >> k;
	
	for(int i=0; i<=200; i++) {
		dp[1][i] = 1;
	}
	
	for(int i=2; i<=k; i++) {
		for(int j=0; j<=n; j++) {
			for(int q=0; q<=j; q++) {
				dp[i][j] = (dp[i][j] + dp[i-1][q]) % 1000000000;
			}
		}
	}
	
	
	cout << dp[k][n];
}