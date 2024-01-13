#include <iostream>

using namespace std;

long long dp[3][1516];

int main() {
	int n;
	cin >> n;
	
	dp[0][1] = 0; dp[2][1] = 0;
	dp[0][2] = 1; dp[1][2] = 1;
	
	for(int i=3; i<=1515; i++) {
		dp[0][i] = (dp[1][i-1] + dp[2][i-1]) % 1000000007;
		dp[1][i] = dp[0][i-1] + dp[2][i-1] % 1000000007;
		dp[2][i] = dp[0][i-1] + dp[1][i-1] % 1000000007;
 	}
	
	cout << dp[0][n];
}