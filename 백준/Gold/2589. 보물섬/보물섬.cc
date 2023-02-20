#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n,m;
string str[51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool check[51][51];
int answer = 0;

struct gold {
	int x;
	int y;
	int cost;
};

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}
}

void bfs(int x, int y) {
	queue<gold> q;
	q.push({x,y,0});
	check[x][y] = true;
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cost = q.front().cost;
		
		answer = max(cost, answer);
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny] || str[nx][ny] == 'W') { continue; }
			check[nx][ny] = true;
			q.push({nx,ny,cost+1});
		} 
	}
}

void initCheck() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			check[i][j] = false;
		}
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(str[i][j] == 'L') {
				bfs(i,j);
				initCheck();
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}