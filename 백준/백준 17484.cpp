#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[7][7];
bool check[7][7];
int min_tmp = 9999999;
int n,m;
int dx[] = {1,1,1};
int dy[] = {-1,0,1};


void dfs(int x,int y,int sum,int dis) 
{
	if(x == n-1) {
		min_tmp = min(min_tmp,sum);
		return;
	}
	
	for(int i=0; i<3; i++) {
		if(i == dis) {
			continue;
		}
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 0 || ny < 0 || nx >= n || ny >= m)	continue;
		dfs(nx,ny,sum + v[nx][ny],i);
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
	
	for(int i=0; i<m; i++) {
		dfs(0,i,v[0][i],-1);
	}
	
	cout << min_tmp;
	
	return 0;
}
