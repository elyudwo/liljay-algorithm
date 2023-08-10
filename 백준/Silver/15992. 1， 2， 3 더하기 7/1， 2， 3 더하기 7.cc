#include <iostream>

using namespace std;

long long dp[1001][1001];

int main() {
	int t;
	
	dp[1][1] = 1;
	dp[2][1] = 1; dp[2][2] = 1;
	dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
	
	for(int i=4; i<=1000; i++) {
		for(int j=2; j<=i; j++) {
			dp[i][j] = (dp[i-1][j-1] % 1000000009 + dp[i-2][j-1] % 1000000009 + dp[i-3][j-1] % 1000000009 ) % 1000000009;
		}
	}
	
	cin >> t;
	
	while(t--) {
		int a,b;
		cin >> a >> b;
		cout << dp[a][b] << '\n';
	}
}