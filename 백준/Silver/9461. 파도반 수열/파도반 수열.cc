#include <iostream>

using namespace std;

long long dp[101];

int main() {
	int t;
	cin >> t;
	
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	
	for(int i=7; i<=100; i++) {
		dp[i] = dp[i-1] + dp[i-5];
	}
	
	while(t--) {
		int tmp;
		cin >> tmp;
		cout << dp[tmp] << '\n';
	}
	
}