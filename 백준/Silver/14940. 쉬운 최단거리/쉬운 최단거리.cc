#include <iostream>
#include <queue>
using namespace std;

int arr[1001][1001];
bool check[1001][1001];
bool check_first[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n,m,start_x,start_y;

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			int tmp;
			cin >> tmp;
			
			arr[i][j] = tmp;
			if(tmp == 2) {
				start_x = i;
				start_y = j;
			}
		}
	}
}

void firstCheck() {
	for(int i=0; i<4; i++) {
		int nx = dx[i] + start_x;
		int ny = dy[i] + start_y;
		
		if(nx < 1 || nx > n || ny < 1 || ny > m || arr[nx][ny] == 0) { continue; }
		check_first[nx][ny] = true;
		
	}
}

void bfs() {
	queue<pair<int,int> > q;
	q.push({start_x,start_y});
	check[start_x][start_y] = true;
	arr[start_x][start_y] = 0;
	
	firstCheck();
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			
			if(nx < 1 || nx > n || ny < 1 || ny > m || check[nx][ny] || arr[nx][ny] == 0) { continue; }
			check[nx][ny] = true; 
			arr[nx][ny] = arr[x][y] + 1;
			q.push({nx,ny});
		}
	}
}

void print() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(check_first[i][j]) {
				cout << "1" << " ";
			}
			else if(arr[i][j] == 1) {
				cout << "-1" << " ";
			}
			else {
				cout << arr[i][j] << " ";
			}
		}
		cout << '\n';
	}
}

void solve() {
	bfs();
	
	print();
}

int main() {
	input();
	solve();
	
	
}