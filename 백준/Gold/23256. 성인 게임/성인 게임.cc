#include <iostream>

using namespace std;

long long dp[1000002][2];

int main() {
	int t;
	cin >> t;
	
	dp[1][0] = 3;
	dp[1][1] = 4;
	
	for(int i=2; i<1000001; i++) {
		dp[i][0] = (dp[i-1][0] * 3) % 1000000007 + dp[i-1][1] % 1000000007;
		dp[i][1] = (dp[i-1][0] * 4) % 1000000007 + (dp[i-1][1] * 2) % 1000000007;
	}
	
	while(t--) {
		int tmp;
		cin >> tmp;
		cout << (dp[tmp][0] + dp[tmp][1]) % 1000000007 << '\n';
	}
}