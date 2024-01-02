#include <iostream>
#define MAX 2000000000;
using namespace std;

int n;
long long t[1510002];
long long p[1510002];
long long dp[1510002];
long long answer = 0;

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> t[i] >> p[i];
	}
}

void solve() {
	long long now = 0;
	
	for(int i=1; i<=n; i++) {
		now = max(now, dp[i]);
		if(t[i] == 1) {
			dp[i] = p[i] + now;
			now = max(now, dp[i]);
			answer = max(answer, dp[i]);
			continue;
		}
		
		now = max(now, dp[i]);
		dp[i + t[i]] = max(dp[i + t[i]], now + p[i]);
		
		if(i + t[i] <= n + 1) {
			answer = max(answer, dp[i + t[i]]);
		}
	}
	
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}