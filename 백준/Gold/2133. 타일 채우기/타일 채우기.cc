#include <iostream>

using namespace std;

long long dp[32];

int main() {
	int n;
	cin >> n;
	
	dp[2] = 3;
	
	for(int i=4; i<=30; i+=2) {
		dp[i] += dp[i-2] * 3 + 2;
		for(int j=4; j<=i; j+=2) {
			dp[i] += dp[i-j] * 2;
		} 
	}
	
	cout << dp[n];
}