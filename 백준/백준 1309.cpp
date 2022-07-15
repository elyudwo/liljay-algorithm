#include <iostream>

using namespace std;

unsigned long long dp[100001];

int main(void)
{
	int n;
	cin >> n;
	
	dp[1] = 3;
	dp[2] = 7;
	dp[3] = 17; 
	for(int i=4; i<=n; i++) {
		dp[i] = (dp[i-2] * 3 + (dp[i-1] - dp[i-2]) * 2) % 9901 ;
	}	
	
	cout << dp[n] ;
	
	return 0;
}
