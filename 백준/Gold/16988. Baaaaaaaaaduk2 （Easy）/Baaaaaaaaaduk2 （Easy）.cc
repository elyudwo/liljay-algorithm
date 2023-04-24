#include <iostream>
#include <queue>

using namespace std;

int n,m;
int arr[21][21];
bool c[21][21];
int answer = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0}; 

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
}

int bfs(int x, int y) {
	queue<pair<int,int> > q;
	q.push({x,y});
	bool check = true;
	int stone = 1;
	c[x][y] = true;
	
	while(!q.empty()) {
		int nx = q.front().first;
		int ny = q.front().second;
		q.pop();
			
		for(int i=0; i<4; i++) {
			int nx_tmp = nx + dx[i];
			int ny_tmp = ny + dy[i];
			
			if(nx_tmp < 0 || ny_tmp < 0 || nx_tmp >= n || ny_tmp >= m || c[nx_tmp][ny_tmp]) {
				continue;
			}
			
			if(arr[nx_tmp][ny_tmp] == 2 && !c[nx_tmp][ny_tmp]) {
				stone += 1;
				q.push({nx_tmp, ny_tmp});
				c[nx_tmp][ny_tmp] = true;
			}
			else if(arr[nx_tmp][ny_tmp] == 0) {
				check = false;
			}
		}
	}
	if(check) {
		return stone;
	}
	else {
		return 0;
	}
	
	
}

int calculate() {
	int sum = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(arr[i][j] == 2 && !c[i][j]) {
				sum += bfs(i,j);
			}
		}
	}
	
	return sum;
}

void init_c() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			c[i][j] = false;
		}
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			for(int k=0; k<n; k++) {
				for(int q=0; q<m; q++) {
					if(arr[i][j] == 0 && arr[k][q] == 0 && !(i == k && j == q)) {
						arr[i][j] = 1;
						arr[k][q] = 1;
						int tmp = calculate();
						answer = max(answer, tmp);
						arr[i][j] = 0;
						arr[k][q] = 0;
						init_c();
					}
				}
			}
		}
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}