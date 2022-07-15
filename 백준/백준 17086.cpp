#include <iostream>
#include <algorithm>
using namespace std;

int v[51][51];
bool check[51][51];
int n,m;
int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {-1,1,0,0,1,-1,1,-1};

int result = 9999;
int final = -1;
void dfs(int x,int y,int cnt) 
{
	for(int i=0; i<8; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 0 || ny < 0 || nx >= n || ny >= m)	continue;
		if(!check[nx][ny] && v[nx][ny] == 1) {
			result = min(result,cnt+1);
			return;
		}
		else if(!check[nx][ny] && v[nx][ny] == 0) {
			check[nx][ny] = true;
			dfs(nx,ny,cnt+1);
			check[nx][ny] = false;
		}
	}
}

int main(void)
{
	scanf("%d %d", &n, &m);
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			scanf("%d", &v[i][j]);
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(v[i][j] == 0) {
				check[i][j] = true;
				dfs(i,j,0);
				final = max(result,final);
				check[i][j] = false;
				result = 9999;
			}
		}
	}
	
	printf("%d",final);
	
	return 0;
}
