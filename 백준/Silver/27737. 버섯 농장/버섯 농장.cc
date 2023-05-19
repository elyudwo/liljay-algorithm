#include <iostream>
#include <cmath>
#include <queue>

using namespace std;

int n,m,k;
int arr[101][101];
bool check[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void input() {
	cin >> n >> m >> k;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
		}
	}
}

int bfs(int x, int y) {
	queue<pair<int,int> > q;
	q.push({x,y});
	check[x][y] = true;
	int cnt = 0;
	
	while(!q.empty()) {
		int x_tmp = q.front().first;
		int y_tmp = q.front().second;
		cnt += 1;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = dx[i] + x_tmp;
			int ny = dy[i] + y_tmp;
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= n || check[nx][ny] || arr[nx][ny] == 1) { continue; }
			check[nx][ny] = true;
			q.push({nx,ny});
		}
	}
	
	return cnt;
}

void solve() {
	double answer = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(arr[i][j] == 0 && !check[i][j]) {
				double cnt = bfs(i,j);
				answer += ceil(cnt/k);
			}
		}
	}
	
	if(answer == 0) {
		cout << "IMPOSSIBLE";
		return;
	}
	
	if(answer <= m) { cout << "POSSIBLE" << "\n"; cout << m - answer; }
	else { cout << "IMPOSSIBLE"; }
}

int main() {
	input();
	solve();
	
}