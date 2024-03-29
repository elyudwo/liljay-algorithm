#include <iostream>

using namespace std;

int dp[15][15];

int main() {
	int t;
	
	for(int i=1; i<15; i++) {
		dp[0][i] = i;
	}
	
	for(int i=1; i<15; i++) {
		for(int j=1; j<15; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	
	cin >> t;
	
	while(t--) {
		int k,n;
		cin >> k;
		cin >> n;
	
		cout << dp[k][n] << endl;	
	}
	
}