#include <iostream>
#include <queue>

using namespace std;

int r,c;
string str[21];
bool alp[26] = {false, };
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int answer = 0;

void input() {
	cin >> r >> c;

	for(int i=0; i<r; i++) {
		cin >> str[i];
	}
}

void dfs(int x, int y, int cnt) {
	answer = max(answer, cnt);
	
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || ny < 0 || nx >= r || ny >= c || alp[str[nx][ny] - 'A']) continue;
		alp[str[nx][ny] - 'A'] = true;
		dfs(nx, ny, cnt + 1);
		alp[str[nx][ny] - 'A'] = false;
	}
	
}

void solve() {
	alp[str[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	 
	cout << answer;
}

int main() {
	input();
	solve();
	
}