#include <iostream>

using namespace std;

int n,m;
int dx[] = {0,0,1,-1,1,1,-1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1};
int cnt = 0;
int v[250][250];
bool c[250][250];

void dfs(int x, int y) 
{
	c[x][y] = true;
	
	for(int i=0; i<8; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
		if(!c[nx][ny] && v[nx][ny] == 1) {
			dfs(nx,ny);
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
				dfs(i,j);
				cnt++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
