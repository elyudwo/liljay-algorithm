#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n,m;
int s_x, s_y, e_x, e_y;
char house[201][201];
bool ghost_time[201][201][4];
bool visit_check[201][201][4];
int dx[5] = {0,1,0,-1,0};
int dy[5] = {1,0,-1,0,0};

void input() {
	cin >> n >> m;
	cin >> s_x >> s_y >> e_x >> e_y;
	
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		for(int j=1; j<=m; j++) {
			house[i][j] = str[j-1];
		}
	}
}

void calculateGhostTime(int x, int y, int dis) {
	for(int i=0; i<4; i++) {
		int nx = dx[(i + dis) % 4];
		int ny = dy[(i + dis) % 4];
		
//		cout << i << " " << nx << " " << ny << '\n';
		
		if(nx > 0) {
			for(int j=x+1; j<=n; j++) {
				if(house[j][y] == '#' || (house[j][y] >= '0' && house[j][y] <= '9')) { break; }
				ghost_time[j][y][i] = true;
			}
		}
		if(ny > 0) {
			for(int j=y+1; j<=m; j++) {
				if(house[x][j] == '#' || (house[x][j] >= '0' && house[x][j] <= '9')) { break; }
				ghost_time[x][j][i] = true;
			}
		}
		if(nx < 0) {
			for(int j=x-1; j>=1; j--) {
				if(house[j][y] == '#' || (house[j][y] >= '0' && house[j][y] <= '9')) { break; }
				ghost_time[j][y][i] = true;
			}
		}
		if(ny < 0) {
			for(int j=y-1; j>=1; j--) {
				if(house[x][j] == '#' || (house[x][j] >= '0' && house[x][j] <= '9')) { break; }
				ghost_time[x][j][i] = true;
			}
		}
	}
	
}

void checkGhost() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(house[i][j] >= '0' && house[i][j] <= '3') {
				calculateGhostTime(i, j, house[i][j] - '0');
			}
		}
	}
}


struct sucjun {
	int x;
	int y;
	int time;
};

void bfs() {
	queue<sucjun> q;
	q.push({s_x, s_y, 0});
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int time = q.front().time;
//		cout << x << y << time << '\n';
		q.pop();
		
		if(ghost_time[x][y][time % 4]) { continue; }
		if(x == e_x && y == e_y) { cout << time; return; }
		
		for(int i=0; i<5; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 1 || nx > n || ny < 1 || ny > m || visit_check[nx][ny][(time+1) % 4] || 
			(house[nx][ny] >= '0' && house[nx][ny] <= '9')|| house[nx][ny] == '#') { continue; }
			if(ghost_time[x][y][time % 4]) { continue; }
			visit_check[nx][ny][(time+1) % 4] = true;
			q.push({nx, ny, time + 1});
		}
	}
	
	cout << "GG";
	return;
}

void solve() {
	checkGhost();
	bfs();
}

int main() {
	input();
	solve();
	
}