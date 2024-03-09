#include <iostream>
#include <algorithm> 
using namespace std;

int n, m;
int dp[5002][5002];

void input() {
	
	cin >> n >> m;
	
	for(int i=0; i<=n+1; i++) {
	    for(int j=0; j<=n+1; j++) {
	        dp[i][j] = -1;
	    }
	}
	
	for(int i=1; i<=m; i++) {
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
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i; j++) {
			dp[i][j] = max({dp[i][j], dp[i-1][j] - 1, dp[i-1][j-1] - 1});
			
			if(dp[i][j] >= 0) { cnt++; }
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