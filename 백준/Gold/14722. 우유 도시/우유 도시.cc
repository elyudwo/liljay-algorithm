#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1002][1002];
int dp[3][1002][1002];
int answer = 0;

void input() {
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
		}
	}	
}

void solve() {
    
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			for(int k=0; k<3; k++) {
				if(k == arr[i][j]) {
				    int next = (k + 1) % 3;
				    if((dp[k][i-1][j] != 0)) {
                        dp[next][i][j] = max(dp[k][i-1][j]  + 1, dp[next][i][j]);
				    }
				    if(dp[k][i][j-1] != 0) {
				        dp[next][i][j] = max(dp[k][i][j-1] + 1, dp[next][i][j]);
				    }
				    
				    if(dp[k][i-1][j] == 0 && arr[i][j] == 0) {
				        dp[next][i][j] = max(dp[next][i][j], 1);
				    }
				    if(dp[k][i][j-1] == 0 && arr[i][j] == 0) {
				        dp[next][i][j] = max(dp[next][i][j], 1);
				    }
				}				
				dp[k][i][j] = max({dp[k][i][j], dp[k][i-1][j], dp[k][i][j-1]});
			}
		}
	}
	
	for(int i=0; i<3; i++) {
		answer = max(answer, dp[i][n][n]);
	}
	
	cout << answer;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
}