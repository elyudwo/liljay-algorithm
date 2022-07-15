#include <iostream>

using namespace std;

long long dp[101];

int main(void)
{
	int t;
	cin >> t;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	dp[4] = 2;
	dp[5] = 2;
	dp[6] = 3;
	dp[7] = 4;
	dp[8] = 5;
	dp[9] = 7;
	dp[10] = 9;
	
	
	for(int i=11; i<=101; i++) {
		dp[i] = dp[i-1] + dp[i-5];
	}
	
	
	while(t--) {
		int n;
		cin >> n;
		cout << dp[n] << endl;
	}
	
	return 0;
}
