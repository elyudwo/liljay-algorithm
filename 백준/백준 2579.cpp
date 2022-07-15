#include <iostream>
#include <algorithm>
using namespace std;

int v[301];
int dp[301]; 
int main(void)
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	dp[3] = max(v[1] + v[3], v[2] + v[3]);
	for(int i=4; i<=n; i++) {
		dp[i] = max(dp[i-2] + v[i], dp[i-3] + v[i-1] + v[i]);
	}
	
	cout << dp[n];
	
	return 0;
}
