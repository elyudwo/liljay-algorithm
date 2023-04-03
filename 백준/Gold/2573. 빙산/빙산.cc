#include <iostream>
#include <queue>

using namespace std;

int n,m;
int arr[301][301];
int arr_rem[301][301];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool check[301][301]; 
int year = 0;

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
}

void bfs(int x,int y) {
	queue<pair<int,int> > q;
	q.push({x,y});
	check[x][y] = true;
	
	while(!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		check[nx][ny] = true;
		q.pop();
		
		int cnt = 0;
		
		for(int i=0; i<4; i++) {
			int nx_tmp = dx[i] + nx;
			int ny_tmp = dy[i] + ny;
			if(nx_tmp < 0 || nx_tmp >= n || ny_tmp < 0 || ny_tmp >= m || check[nx_tmp][ny_tmp]) { continue; }
			if(arr[nx_tmp][ny_tmp] && !check[nx_tmp][ny_tmp]) {
				q.push({nx_tmp,ny_tmp});
				check[nx_tmp][ny_tmp] = true;
			}
			else if(arr[nx_tmp][ny_tmp] == 0) {
				cnt += 1;
			}
		}
		
		arr_rem[nx][ny] = arr[nx][ny] - cnt;
	}
	
}

void init() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			check[i][j] = false;
		}
	}
}

void copy() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr_rem[i][j] <= 0) {
				arr[i][j] = 0;
			} 
			else {
				arr[i][j] = arr_rem[i][j];
			}
			check[i][j] = false;
			arr_rem[i][j] = 0;
		}
	}
}

bool allCheck() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] > 0) {
				return true;
			}
		}
	}
	return false;
}

void print() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	cout << endl;
}

void solve() {
	while(1) {
		int cnt = 0;
		year += 1;
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(arr[i][j] && !check[i][j]) {
					bfs(i,j);
					cnt += 1;
				} 
			}
		}
		copy();
		if(cnt > 1) {
			cout << year-1;
			return;
		}
		if(!allCheck()) {
			break;
		}
	}
	
	cout << "0";
}

int main() {
	input();
	solve();
	
	
}