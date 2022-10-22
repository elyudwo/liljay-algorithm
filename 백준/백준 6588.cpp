#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main(void)
{
	
	int n;
	cin >> n;
	
	int cnt = 0;
	
	for(int i=0; i<1000001; i++) {
		dp[i] = 1000001;
	}
	
	for(int i=1; i<1000001; i++) {
		cnt++;
		dp[i*3] = min(dp[i*3],cnt);
		dp[i*2] = min(dp[i*2],cnt);
		dp[i+1] = min(dp[i+1],cnt);
	} 
	
	cout << dp[n];
	
	
	
	return 0;
}
