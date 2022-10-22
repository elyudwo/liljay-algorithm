#include <iostream>
#include <algorithm>

using namespace std;

int v[1001];
int dp[1001];

int main(void)
{
	int n;
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	int result = 1;
	
	for(int i=0; i<=1000; i++) {
		dp[i] = 1;
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=i; j<=n; j++) {
			if(v[j] > v[i]) {
				dp[j] = max(dp[j],dp[i] + 1);
				result = max(result,dp[j]);
			}
		}
		
	}
	cout << result;
	
	return 0;
}
