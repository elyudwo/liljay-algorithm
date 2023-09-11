#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n,m,k;
string str[1001];
bool check[1001][1001][11];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int answer = -1;

struct person {
	int x;
	int y;
	int cnt;
	int num;
};

void input() {
	cin >> n >> m >> k;
	for(int i=0; i<n; i++) {
		cin >> str[i];
	}
}

void bfs() {
	queue<person> q;
	q.push({0,0,0,1});
	check[0][0][0] = true;
	
	while(!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		int num = q.front().num;
		q.pop();
		
		if(x == n-1 && y == m-1) {
			answer = num;
			break;
		}
		
		for(int i=0; i<4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			
			if(check[nx][ny][cnt] || nx < 0 || ny < 0 || nx >= n || ny >= m || cnt > k) { continue; }
			
			
			if(str[nx][ny] == '1' && !check[nx][ny][cnt+1] && cnt + 1 <= k) {
				q.push({nx, ny, cnt+1, num+1}); 
				check[nx][ny][cnt+1] = true;
			}
			else if(str[nx][ny] == '0' && !check[nx][ny][cnt]) { 
				q.push({nx, ny, cnt, num+1}); 
				check[nx][ny][cnt] = true;
			}
		}
		
	}
	
}

void solve() {
	bfs();
	cout << answer;
}

int main() {
	input();
	solve();
	
}