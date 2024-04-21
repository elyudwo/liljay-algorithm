#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1002][1002];
// 0 == 왼쪽에서 오는 것, 1 == 오른쪽에서 오는 것 
int dp[2][1002][1002];

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
	
	for(int i=0; i<=1001; i++) {
	    for(int j=0; j<=1001; j++) {
	        dp[0][i][j] = -2000000000;
	        dp[1][i][j] = -2000000000;
	    }
	}
}

void solve() {
	
	dp[0][1][1] = arr[1][1];
	for(int i=2; i<=m; i++) {
		dp[0][1][i] = arr[1][i] + dp[0][1][i-1];
	}
	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			dp[0][i][j] = arr[i][j] + max({dp[0][i-1][j], dp[1][i-1][j], dp[0][i][j-1]});
		}
		
		for(int j=m; j>=1; j--) {
			dp[1][i][j] = arr[i][j] + max({dp[0][i-1][j], dp[1][i-1][j], dp[1][i][j+1]});
		}
	}
	
	
	cout << max(dp[0][n][m], dp[1][n][m]);
}

int main() {
	input();
	solve();
	
}