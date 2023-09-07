#include <iostream>

using namespace std;

int n;
int arr[101];
long long dp[101][21];

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	dp[1][arr[1]] = 1;
	
	for(int i=2; i<n; i++) {
		for(int j=0; j<=20; j++) {
			if(dp[i-1][j]) {
				if(j + arr[i] <= 20) {
					dp[i][j+arr[i]] += dp[i-1][j];
				}
				if(j - arr[i] >= 0) {
					dp[i][j-arr[i]] += dp[i-1][j];
				}
			}
		}
	}
	
	
//	for(int i=1; i<n; i++) {
//		for(int j=0; j<=20; j++) {
//			cout << dp[i][j] << " ";
//		}
//		cout << endl;
//	}
	
	cout << dp[n-1][arr[n]];
}

int main() {
	input();
	solve();
	
}