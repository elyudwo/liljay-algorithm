#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

string str[1002];
int fire_time[1002][1002];
int now_x, now_y;
int n, m;
vector<pair<int,int> > fire; 
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

struct person {
	int x;
	int y;
	int cnt;
};

bool cornerCase(int x, int y) {
	if(x == 0 || x == m-1 || y == 0 || y == n-1) {
		return true;
	}
	return false;
}

void bfs() {
	queue<person> q;
	q.push({now_x, now_y, 0});
	bool check[1002][1002] = {false,};
	check[now_x][now_y] = true;
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		
		q.pop();
		
		if(cornerCase(x, y)) {
			cout << cnt + 1 << '\n';
			return;
		}
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(nx < 0 || nx >= m || ny < 0 || ny >= n || str[nx][ny] == '#' || fire_time[nx][ny] <= cnt + 1 || check[nx][ny]) {
				continue;
			}
			check[nx][ny] = true;
			q.push({nx, ny, cnt + 1});
		}
	}
	
	cout << "IMPOSSIBLE" << '\n';
	return;
}

struct fire_rem {
	int x;
	int y;
	int cnt;
};

void calculateFireTime() {
	queue<fire_rem> q;
	bool check[1001][1001] = {false,};
	
	for(int i=0; i<fire.size(); i++) {
		q.push({fire[i].first, fire[i].second, 0});
		check[fire[i].first][fire[i].second] = true;
	}
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		
		q.pop();
		fire_time[x][y] = cnt;
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(check[nx][ny] || nx < 0 || nx >= m || ny < 0 || ny >= n || str[nx][ny] == '#') continue;
			check[nx][ny] = true;
			q.push({nx, ny, cnt + 1});
		}
	}
}

void init() {
	for(int i=0; i<m; i++) {
		str[i].clear();
		for(int j=0; j<n; j++) {
			fire_time[i][j] = INF;
		}
	}
	
	fire.clear();
}

void printFire() {
	for(int i=0; i<m; i++) {
		for(int j=0; j<n; j++) {
			cout << fire_time[i][j] << " ";
		}
		cout << '\n';
	}
}

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		cin >> n >> m;
		init();
		
		for(int i=0; i<m; i++) {
			cin >> str[i]; 
			
			for(int j=0; j<n; j++) {
				if(str[i][j] == '@') {
					now_x = i;
					now_y = j;
				}
				if(str[i][j] == '*') {
					fire.push_back({i, j});
				}
			}
		}
		
		calculateFireTime();
//		printFire();
		bfs();
		
	}
	
}