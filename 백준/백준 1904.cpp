#include <iostream>

using namespace std;

long long dp[1000001];

int main(void)
{
	int n;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 5;
	
	for(int i=5; i<=1000000; i++) {
		dp[i] = (dp[i-2] + dp[i-1]) % 15746;
	}
	
	cout << dp[n];
	
	return 0;
}
