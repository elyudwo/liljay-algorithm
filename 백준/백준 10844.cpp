#include <iostream>

using namespace std;

long long dp[101][10];

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=1; i<=9; i++) {
		dp[1][i] = 1;
	}
	
	for(int i=1; i<=8; i++) {
		dp[2][i] = 2;
	}
	dp[2][0] = 1;
	dp[2][9] = 1;
	int tmp = 1;
	
	for(int i=3; i<=100; i++) {
		dp[i][0] = dp[i-1][1] % 1000000000;
		for(int j=1; j<=8; j++) {
			dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000;
		}
		dp[i][9] = dp[i-1][8] % 1000000000;
		tmp++;
	}
	
	long long sum = 0;
	
	for(int i=1; i<=9; i++) {
		sum = (sum + dp[n][i]) % 1000000000;
	}
	
	cout << sum % 1000000000;
	
	
	return 0;
}
