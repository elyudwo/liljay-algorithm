#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int arr[51][51];

// 3 == ³², 2 == µ¿, 1 == ºÏ, 0 == ¼­ 
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool wall[51][51][4];
bool check[51][51];
int room_cnt = 0;
int max_room = -1;
int real_max_room = -1;

string convert(int tmp) {
	string str = "";
	while(tmp != 0) {
		str = char(tmp % 2 + '0') + str;
		tmp = tmp/2;
	}
	
	if(str.length() < 4) {
		int s = str.length();
		for(int i=0; i<4-s; i++) {
			str = "0" + str;
		}
	}
	
	return str;
}

void input() {
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cin >> arr[i][j];
			string str = convert(arr[i][j]);
			for(int k=0; k<4; k++) {
				if(str[k] == '0') {
					wall[i][j][k] = true;
				}
			}
		}
	}
}

void bfs(int a,int b,int c) {
	queue<pair<int,int> > q;
	q.push({a,b});
	int cnt = 0;
	check[a][b] = true;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		cnt++;
		q.pop();
		
		for(int i=0; i<4; i++) {
			if(!wall[x][y][i]) continue;
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= m || ny < 0 || ny >= n || check[nx][ny]) continue;
			check[nx][ny] = true;
			q.push({nx,ny});
		}
	}
	
	if(c == 1) { max_room = max(max_room,cnt); }
	else { real_max_room = max(real_max_room,cnt); }
}

void check_init() {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			check[i][j] = false;
		}
	}
}

void solve() {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			if(!check[i][j]) {
				room_cnt++;
				bfs(i,j,1);
			}
		}
	}
	
	check_init();
	
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			for(int k=0; k<4; k++) {
				if(!wall[i][j][k]) {
					wall[i][j][k] = true;
					bfs(i,j,2);
					check_init();
					wall[i][j][k] = false;
				}
			}
		}
	}
	
	cout << room_cnt << '\n' << max_room << '\n' << real_max_room;
}

int main() {
	input();
	solve();
	
}
