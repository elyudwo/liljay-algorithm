#include <iostream>

using namespace std;

long long dp[46];

int main(void)
{
	int n;
	cin >> n;
	
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	for(int i=3; i<=90; i++) {
		dp[i] = dp[i-1] + dp[i-2];
	} 
	cout << dp[n];
	
	return 0;
}
