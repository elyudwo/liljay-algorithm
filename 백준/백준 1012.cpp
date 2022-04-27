#include <iostream>
#include <vector>
#include <cstring> 
using namespace std;

bool c[51][51];
int cab[51][51];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int m,n,k;

void dfs(int x,int y) 
{
	c[x][y] = true;
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx >= 0 && nx < n && ny >=0 && ny < m) {
			if(cab[nx][ny] == 1) {
				if(!c[nx][ny]) {
					dfs(nx,ny);
				}
			}
		}
	}
}

int main(void)
{
	int t;
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> m >> n >> k;
		int cnt = 0;
		for(int i=0; i<k; i++) {
			int a,b;
			cin >> a >> b;
			cab[a][b] = 1;
		}
		for(int i=0; i<n; i++) {
			for(int j=0; j<m; j++) {
				if(cab[i][j] == 1) {
					if(!c[i][j]) {
						cnt++;
						dfs(i,j);
					}
				}
			}
		}
		cout << cnt << endl;
		memset(c,false,sizeof(c));
		memset(cab,0,sizeof(c));	
	}
}
