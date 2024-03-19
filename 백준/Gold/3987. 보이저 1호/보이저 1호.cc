#include <iostream>
#define INF 2e9
using namespace std;

char arr[502][502];
bool check[502][502][4];
int n,m;
int start_x, start_y;
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};
int answer = 0;
int answer_tmp = 0;
char direction[4] = {'U', 'R', 'D', 'L'};
int dir_idx;

void input() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		for(int j=1; j<=m; j++) {
			arr[i][j] = str[j-1];
		}
	}

	cin >> start_x >> start_y;
}

void dfs(int x, int y, int dir, int cnt) {
	if(x < 1 || y < 1 || x > n || y > m || arr[x][y] == 'C') {
		answer_tmp = max(answer_tmp, cnt);
		return;
	}
	
	check[x][y][dir] = true;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	
	if(check[nx][ny][dir]) {
		answer_tmp = INF;
		return;
	} 
	
	// 행성 
	if(arr[nx][ny] == '/') {
		if(dir == 0) {
			dfs(nx, ny, 1, cnt + 1);
		}
		else if(dir == 1) {
			dfs(nx, ny, 0, cnt + 1);
		}
		else if(dir == 2) {
			dfs(nx, ny, 3, cnt + 1);
		}
		else if(dir == 3) {
			dfs(nx, ny, 2, cnt + 1);
		}
	}
	else if(arr[nx][ny] == '\\') {
		if(dir == 0) {
			dfs(nx, ny, 3, cnt + 1);
		}
		else if(dir == 1) {
			dfs(nx, ny, 2, cnt + 1);
		}
		else if(dir == 2) {
			dfs(nx, ny, 1, cnt + 1);
		}
		else if(dir == 3) {
			dfs(nx, ny, 0, cnt + 1);
		}
	} 
	else {
		dfs(nx, ny, dir, cnt + 1);
	}
}

void init() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int k=0; k<4; k++) {
				check[i][j][k] = false;
			}
		}
	}
}

void solve() {
	for(int i=0; i<4; i++) {
		dfs(start_x, start_y, i, 0);
//		cout << answer_tmp << " ";
		if(answer_tmp > answer) {
			answer = answer_tmp;
			dir_idx = i;
			
		}
		init();
		
		answer_tmp = 0;
	}
	
	if(answer == INF) {
		cout << direction[dir_idx] << '\n' << "Voyager";
		return;
	}
	
	cout << direction[dir_idx] << '\n' << answer;
}

int main() {
	input();
	solve();
	
}