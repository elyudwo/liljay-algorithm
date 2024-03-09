#include <iostream>
#include <algorithm> 
using namespace std;

int n;
long long dp[2002][2002];

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		if(dp[a][b] < c) {
			dp[a][b] = c;
		}
		
	}
}

void print() {
    cout << '\n';
    for(int i=1; i<=5; i++) {
		for(int j=1; j<=5; j++) {
			cout << dp[i][j] << " ";
		}
		cout << '\n';
	}
}

void solve() {
	int cnt = 0;
	for(int i=1; i<=2000; i++) {
		for(int j=1; j<=2000; j++) {
			dp[i][j] = max({dp[i][j], dp[i][j-1] - 1, dp[i-1][j-1] - 2});
			dp[i][j] = max(dp[i][j],  dp[i-1][j] - 1);
			if(dp[i][j] > 0) { cnt++; }
		}
	}
	
	cout << cnt;
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	input();
	solve();
	
}