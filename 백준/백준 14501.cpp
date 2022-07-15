#include <iostream>
#include <algorithm>
using namespace std;


int v[16];
int time[16];
int dp[16];

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		cin >> time[i] >> v[i];
	}
	
	for(int i=1; i<=n; i++) {
		if(i + time[i] > n+1) continue;
		if(i + time[i] == n+1) {
			dp[i+time[i] - 1] = max(dp[i] + v[i],dp[i+time[i]]);
		}
		for(int j=i+time[i]; j<=n; j++) {
			dp[j] = max(dp[i] + v[i],dp[j]);
		}
	}
	
	sort(dp+1,dp+(n+1));
	cout << dp[n];
	
	return 0;
}
