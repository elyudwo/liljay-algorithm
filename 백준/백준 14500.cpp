#include <iostream>
#include <vector>
#include <algorithm>
#include<cstring>

using namespace std;
int result = 0;
int v[501][501];
int check[501][501];
int n,m;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

void dfs(int x,int y,int cnt,int sum)
{
	if(cnt == 4) {
		if(result < sum) {
			result = sum;
		}
		return;
	}
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 1 || ny < 1 || nx > n || ny > m || check[nx][ny])	continue;
		check[nx][ny] = 1;
		dfs(nx,ny,cnt+1,sum+v[nx][ny]);
		check[nx][ny] = 0;
	}
	
	if(x-1>=1 && y-1>=1 && x+1<=n) {
		result = max(result,(v[x-1][y] + v[x][y-1] + v[x][y] + v[x+1][y]));
	}
	if(x-1>=1 && y+1<=m && x+1<=n) {
		result = max(result,(v[x-1][y] + v[x][y+1] + v[x][y] + v[x+1][y]));
	}
	if(y-1>=1 && x+1<=n && y+1<=m) {
		result = max(result,(v[x][y] + v[x+1][y] + v[x+1][y+1] + v[x+1][y-1]));
	}
	if(y-1>=1 && x+1<=n && y+1<=m) {
		result = max(result,(v[x][y-1] + v[x][y] + v[x][y+1] + v[x+1][y]));
	}
}


int main(void)
{
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			cin >> v[i][j];
		}
	}
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			check[i][j] = 1;
			dfs(i,j,1,v[i][j]);
			check[i][j] = 0;
		}
	}
	cout << result;
	return 0;
}
