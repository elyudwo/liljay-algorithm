#include <iostream>
#include <queue>

using namespace std;

int n,m;
int time = 0;
int rem = 0;
int arr[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool check[101][101];

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j]; 
		}
	}
}

bool allCheck() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 1)  { return false; }
		}
	}
	return true;
}

void bfs() {
	queue<pair<int,int> > q;
	q.push({0,0});
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 0 || ny < 0 || nx >= n || ny >= m || check[nx][ny]) continue;
			check[nx][ny] = true;
			if(arr[nx][ny] == 1) {
				arr[nx][ny] = 2;
				continue;
			}
			else if(arr[nx][ny] == 0) { q.push({nx,ny}); }
		}
	}
}

void eraseCheeze() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 2) {
				arr[i][j] = 0;
			}
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

void howMuch() {
	int result = 0;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 1) {
				result += 1;
			}
		}
	}
	rem = result;
}

void solve() {
	while(1) {
		howMuch();
		bfs();
		eraseCheeze();
		time += 1;
		initCheck();
		if(allCheck()) {
			break;
		}
	}
	
	cout << time << '\n' << rem;
}

int main() {
	input();
	solve();
	
}