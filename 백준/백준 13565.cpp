#include <iostream>
#include <stdlib.h>
#include <cstring>
using namespace std;

int n,m;

string v[1000];
bool c[1000][1000];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dfs(int x,int y) 
{
	c[x][y] = true;
	if(x == n-1) {
		cout << "YES";
		exit(0);
	}
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx<0 || nx>=n || ny < 0 || ny >= m)	continue;
		if(v[nx][ny] == '0' && !c[nx][ny]) {
			dfs(nx,ny);
		}
	} 
	
	
}

int main(void)
{
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}
	
	for(int i=0; i<m; i++) {
		if(v[0][i] == '0') {
			dfs(0,i);
		}
	}	
	
	cout << "NO";
	
	return 0;
}
