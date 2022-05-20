#include <iostream>
#include <queue>
#include <string>

using namespace std;
int n,m;
string s[100];
int c[100][100];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(int x,int y)
{
	queue<pair<int,int>> q;
	q.push({x,y});
	c[x][y] = 1;
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		
		for(int i=0; i<4; i++) {
			int nx = dx[i] + x;	
			int ny = dy[i] + y;
			
			if(nx < 0 || nx >=n || ny < 0 || ny >= m) continue;
			if(c[nx][ny] == 0 && s[nx][ny] == '1') {
				c[nx][ny] = c[x][y] + 1; 
				q.push({nx,ny});
			}
		}
	}	
}

int main(void)
{
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> s[i];
	}
	
	bfs(0,0);
	
	cout << c[n-1][m-1];
	
	return 0;
}
