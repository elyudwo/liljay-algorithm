#include <iostream>
#include <queue>

using namespace std;

int n,m,k;
int answer = 0;
int dx[] = {1,0};
int dy[] = {0,1};

int arr[16][16];

void input() {
	cin >> n >> m >> k;
	int cnt = 1;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(cnt == k) { arr[i][j] = 0; }
			else { arr[i][j] = 1; }
			cnt++;
		}
	}
	
}

void dfs(int x, int y,bool c) {
	if(x == n-1 && y == m-1 && c == true) {
		answer++;
		return;
	}
	
	for(int i=0; i<2; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 0 || ny < 0 || nx >= n || ny >= m ) { continue; }
		if(arr[nx][ny] == 0) {
			dfs(nx,ny,true);
		}
		else {
			dfs(nx,ny,c);
		}
	
	}
}

void solve() {
	if(k == 0) {
		dfs(0,0,true);
	}
	else {
		dfs(0,0,false);
	}
	cout << answer;
}

int main() {
	input(); 
	solve();
	
}