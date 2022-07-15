#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int n,m,r,c,d;
int v[51][51];

bool check[51][51];
int result = 0; 
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void dfs(int x,int y,int dis,int sum)
{
	for(int i=0; i<4; i++) {
	    int nd = (dis+3-i) % 4;
		int nx = x + dx[nd];
		int ny = y + dy[nd];
		
		
		if(nx < 0 || ny < 0 || nx>=n || ny>=m)	continue;
		
		if(!check[nx][ny] && v[nx][ny] == 0) {
		    check[nx][ny] = true;
			dfs(nx,ny,nd,sum+1);
		}
	}
	int nx_back = x + dx[(dis+2) % 4];
	int ny_back = y + dy[(dis+2) % 4];
	
	if(nx_back>=0 && ny_back>=0 && nx_back<=n && ny_back<=m) {
	    if(v[nx_back][ny_back] == 0) {
	        dfs(nx_back,ny_back,dis,sum);
	    }
	    else {
	        cout << sum;
	        exit(0);
	    }
	}
	
}


int main(void)
{
	cin >> n >> m;
	cin >> r >> c >> d;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> v[i][j];
		}
	}
	check[r][c] = true;
	dfs(r,c,d,1);
	
	return 0;
}
