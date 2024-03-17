#include <iostream>

using namespace std;

int n;
int arr[502][502];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int dp[502][502];
int answer = 1;

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> arr[i][j];
		}
	}
}

int dfs(int x, int y) {	
	if(dp[x][y]) return dp[x][y];
	
	dp[x][y] = 1;

	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(arr[nx][ny] > arr[x][y]) {
			dp[x][y] = max(dfs(nx,ny) + 1, dp[x][y]);
		}
	}
	
	return dp[x][y];
}

void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			answer = max(answer, dfs(i,j));
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}