#include <iostream>
#include <algorithm> 
using namespace std;

int v[10001];
int dp[10001];
int main(void)
{
	int n;
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> v[i];
	}
	
	int result = 0;
	

	dp[0] = 0;
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	
	for(int i=3; i<=n; i++) {
		int max;
		int a,b,c;
		a = dp[i-2] + v[i];
		b = dp[i-3] + v[i-1] + v[i];
		c = dp[i-1];
		if(a > b) {
			max = a;
		}
		else {
			max = b;
		}
		
		if(max > c) {
			
		}
		else {
			max = c;
		}
	
		dp[i] = max;
	}
	
	for(int i=n-3; i<=n; i++) {
		result = max(result,dp[i]);
	}
	
	
	
	
	cout << result;
	return 0;
}
