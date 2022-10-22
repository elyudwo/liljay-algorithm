#include <iostream>

using namespace std;

int v[17][17];
int result = 0;
 // 0 == garo	1 == sero	 2 == degac
int dx[] = {0,1,1};
int dy[] = {1,0,1};

int n;

void dfs(int x,int y,int tmp)
{
	if(x == n && y == n) {
		result++;
		return;
	}
	
	for(int i=0; i<3; i++) {
		if((tmp == 0 && i == 1) || (tmp == 1 && i == 0))	continue;
		
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 1 || nx > n || ny < 1 || ny > n || v[nx][ny] == 1)	continue;
		if(i==2 && (v[x+1][y] == 1 || v[x][y+1] == 1))	continue;
		dfs(nx,ny,i);
	}
}

int main(void)
{
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> v[i][j];
		}
	}
	
	dfs(1,2,0);
	
	cout << result;
	
	return 0;
}
