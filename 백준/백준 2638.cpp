#include <iostream>
#include <queue>

using namespace std;

int n,m;
int arr[101][101];
bool air[101][101];
int time = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0}; 

void input() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> arr[i][j];
		}
	}
}

bool checkDis(int x, int y) {
	int zero = 0;
	
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!air[nx][ny]) {
			zero++;
		}
	}
	
	if(zero > 2) { return true; }
	else { return false; } 
}

void checkMelting() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(arr[i][j] == 1 && !checkDis(i,j)) {
				arr[i][j] = 0;
			}
		}
	}
}

bool allCheck() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(arr[i][j] == 1) {
				return false;
			}
		}
	}
	
	return true;
}


void checkAir() {
	queue<pair<int,int> > q;
	q.push({1,1});
	air[1][1] = true;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		air[x][y] = true;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(nx < 1 || nx > n || ny < 1 || ny > m || air[nx][ny] || arr[nx][ny] == 1) { continue; }
			q.push({nx,ny});
			air[nx][ny] = true;
		}
	}
}

void solve() {
	while(1) {
		time++;
		
		checkAir(); 
		checkMelting();
		
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				air[i][j] = false;
			}
		}
		
		if(allCheck()) {
			cout << time;
			break;
		}
	}
	
}

int main() {
	input();
	solve();
	
}
