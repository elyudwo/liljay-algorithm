#include <iostream>

using namespace std;

long long dp[100001][3];

int main() {
	int t;
	
	dp[1][1] = 1;
	dp[2][1] = 1; dp[2][2] = 1;
	dp[3][1] = 2; dp[3][2] = 2;
	
	for(int i=4; i<=100000; i++) {
		dp[i][1] = (dp[i-1][2] + dp[i-2][2] + dp[i-3][2]) % 1000000009;
		dp[i][2] = (dp[i-1][1] + dp[i-2][1] + dp[i-3][1]) % 1000000009;
	}
	
	cin >> t;
	
	while(t--) {
		int a,b;
		cin >> a;
		
		
		cout << dp[a][1] << " " << dp[a][2] << '\n';
	}
}