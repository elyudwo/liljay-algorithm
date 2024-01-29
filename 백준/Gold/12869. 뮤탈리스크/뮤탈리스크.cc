#include <iostream>
#define INF 1e9

using namespace std;

int dp[70][70][70];
int n;
int scv[3];

void input() {
	cin >> n;
	
	for(int i=0; i<n; i++) {
		cin >> scv[i];
	}
	
	for(int i=0; i<=69; i++) {
		for(int j=0; j<=69; j++) {
			for(int k=0; k<=69; k++) {
				dp[i][j][k] = INF;
			}
		}
	}
}

void solve() {
	dp[scv[0]][scv[1]][scv[2]] = 0;
	
	for(int i=scv[0]; i>=-9; i--) {
		for(int j=scv[1]; j>=-9; j--) {
			for(int k=scv[2]; k>=-9; k--) {
				dp[max(0,i)][max(0,j)][max(0,k)] = min(dp[max(0,i)][max(0,j)][max(0,k)], dp[max(0, i + 9)][max(0,j + 3)][max(0,k + 1)] + 1);
				dp[max(0,i)][max(0,j)][max(0,k)] = min(dp[max(0,i)][max(0,j)][max(0,k)], dp[max(0, i + 9)][max(0,j + 1)][max(0,k + 3)] + 1);
				dp[max(0,i)][max(0,j)][max(0,k)] = min(dp[max(0,i)][max(0,j)][max(0,k)], dp[max(0, i + 3)][max(0,j + 9)][max(0,k + 1)] + 1);
				dp[max(0,i)][max(0,j)][max(0,k)] = min(dp[max(0,i)][max(0,j)][max(0,k)], dp[max(0, i + 3)][max(0,j + 1)][max(0,k + 9)] + 1);
				dp[max(0,i)][max(0,j)][max(0,k)] = min(dp[max(0,i)][max(0,j)][max(0,k)], dp[max(0, i + 1)][max(0,j + 3)][max(0,k + 9)] + 1);
				dp[max(0,i)][max(0,j)][max(0,k)] = min(dp[max(0,i)][max(0,j)][max(0,k)], dp[max(0, i + 1)][max(0,j + 9)][max(0,k + 3)] + 1);
				
			}
		}
	}
	
	cout << dp[0][0][0];
}

int main() {
	input();
	solve();
}