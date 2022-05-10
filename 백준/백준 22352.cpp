#include <iostream>

using namespace std;

int v1[31][31];
int v2[31][31];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
bool stop;
bool c[31][31];
bool lee = true;
int n,m;

void dfs(int x,int y,int z,int k)
{
	if(c[x][y])	return;
	
	c[x][y] = true;
	
	v1[x][y] = k;
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || nx >= n || ny < 0 || ny >= m)	continue;
		if(!c[nx][ny] && v1[nx][ny] == z) {
			dfs(nx,ny,z,k);
		}
	}
}

int main(void)
{
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> v1[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> v2[i][j];
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(v1[i][j] != v2[i][j]) {
				dfs(i,j,v1[i][j],v2[i][j]);
				stop = true;
				break;
			}
		}
		if(stop)
			break;
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(v1[i][j] != v2[i][j])
				lee = false;
		}
	}
	

	if(lee)
		cout << "YES";
	else
		cout << "NO";
	
	
	return 0;
}
