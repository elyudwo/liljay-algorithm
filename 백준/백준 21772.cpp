#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

char vec[101][101];
int n,m,t;
int gahi_x,gahi_y;
int result = -1;
int dx[] = {0,0,0,1,-1};
int dy[] = {0,1,-1,0,0};

void input() {
	cin >> n >> m >> t;
	string str;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> vec[i][j];
			if(vec[i][j] == 'G') {
				gahi_x = i;
				gahi_y = j;
			}
		}
	}
}

void dfs(int x,int y,int time,int cnt) {
	if(time == t) {
		result = max(result,cnt);
		return;
	}
	for(int i=0; i<5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		int t = time + 1;
		int c = cnt;
		if(nx < 0 || nx > n || ny < 0 || ny > m || vec[nx][ny] == '#') continue;
		bool tmp = false;
		
		if(vec[nx][ny] == 'S') {
			c++;
			vec[nx][ny] = '.';
			tmp = true;
		}
		dfs(nx,ny,t,c);
		if(tmp) {
			vec[nx][ny] = 'S';
		}
	}
}

int main() {
	input();
	dfs(gahi_x,gahi_y,0,0);
	
	cout << result;
}
