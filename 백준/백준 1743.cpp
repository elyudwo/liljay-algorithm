#include <iostream>
#include <algorithm>
using namespace std;

int n,m,k;
int v[100][100];
bool c[100][100];


int cnt;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
void dfs(int x, int y)
{
	if(c[x][y])	return;
	cnt++;
	c[x][y] = true;
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
		if(!c[nx][ny] && v[nx][ny] == 1) {
			dfs(nx,ny);
		}
	}
}

int main(void)
{
	cin >> n >> m >> k;
	
	for(int i=0; i<k; i++) {
		int a,b;
		cin >> a >> b;
		v[a-1][b-1] = 1;
	}
	
	int maxcnt = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(!c[i][j] && v[i][j] == 1) {
				cnt = 0;
				dfs(i,j);
				maxcnt = max(maxcnt,cnt);
			}
		}
	}
	
	cout << maxcnt;
	
	return 0;
}
