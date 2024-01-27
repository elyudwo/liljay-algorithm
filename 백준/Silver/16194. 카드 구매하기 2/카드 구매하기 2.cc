#include <iostream>
#define INF 1e9

using namespace std;

long long dp[1002];
int n;
int arr[10002];

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		dp[i] = INF;
	}	
}

void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			dp[i] = min(dp[i], dp[i - j] + arr[j]);
		}
	}
	
	cout << dp[n];
}

int main() {
	input();
	solve();
	
}