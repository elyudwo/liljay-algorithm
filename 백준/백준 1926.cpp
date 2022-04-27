#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n,m;
int cnt,width;
int maxWidth;
int v[500][500];
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
bool c[500][500];

void bfs(int x,int y) 
{
	queue<pair<int,int>> q;
	q.push(pair<int,int>(x,y));
	c[x][y] = true;
	
	while(!q.empty()) {
		width++;
		int lee = q.front().first;
		int shin = q.front().second;
		q.pop();
		
		for(int i=0; i<4; i++) {
			int nx = dx[i] + lee;
			int ny = dy[i] + shin;
			
			if(nx<0 || nx>=n || ny<0 || ny >=m )  continue;
			if(!c[nx][ny] && v[nx][ny] == 1) {
				q.push(pair<int,int>(nx,ny));
				c[nx][ny] = true;
			}
		}
	}
}

int main(void) 
{
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> v[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!c[i][j] && v[i][j] == 1) {
				width = 0;
				bfs(i,j);
				cnt++;
				maxWidth = max(maxWidth,width);
			}
		}
	}
	cout << cnt << "\n" << maxWidth;
	
	return 0;
}
