#include <iostream>
#include <vector>

using namespace std;

int n,s,m;
int arr[51];
int dp[51][1001];

void input() {
	cin >> n >> s >> m;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	dp[0][s] = 1;
	int answer = -1;
	
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=m; j++) {
			if(dp[i-1][j] && j - arr[i] >= 0) { dp[i][j - arr[i]] = 1; }
			if(dp[i-1][j] && j + arr[i] <= m) { dp[i][j + arr[i]] = 1; }
		}
	}
	
	for(int i=0; i<=m; i++) { if(dp[n][i]) { answer = i; } }
	cout << answer;
}

int main() {
	input();
	solve();
	
}