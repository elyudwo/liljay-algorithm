#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	int dp[100001];
	
	for(int i=0; i<100001; i++) {
		dp[i] = i;
	}
	
	for(int i=1; i<100001; i++) {
		for(int j=1; j*j<=i; j++) {
			dp[i] = min(dp[i], dp[i-j*j] + 1);
		}
	}
	
	cout << dp[n];
	
}