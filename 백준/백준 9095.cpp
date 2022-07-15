#include <iostream>

using namespace std;

int main(void)
{
	int t;
	cin >> t;
	int dp[12] = {0,};
	
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	/*
	dp[4] = 7;
	dp[5] = 14;
	dp[6] = 25;
	*/
	for(int i=4; i<=11; i++) {
		dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
	}
	
	
	while(t--) {
		int n;
		cin >> n;
		
		cout << dp[n] << endl;
		
	}
	
	return 0;
}
