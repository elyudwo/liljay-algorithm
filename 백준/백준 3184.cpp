#include <iostream>

using namespace std;

int r,c;
char v[250][250];
bool check[250][250];

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int l,w = 0;
int lamb = 0;
int wolf = 0;

void dfs(int x,int y) 
{
	check[x][y] = true;
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || nx >= r || ny < 0 || ny >= c || v[nx][ny] == '#') continue;
		if(!check[nx][ny]) {
			if(v[nx][ny] == 'v') {
				w++;
				dfs(nx,ny);
			}
			else if(v[nx][ny] == 'o') {
				l++;
				dfs(nx,ny);
			}
			else if(v[nx][ny] == '.') {
				dfs(nx,ny);
			}
		}
	}
}

int main(void)
{
	cin >> r >> c;
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			cin >> v[i][j];
		}
	}
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(!check[i][j]) {
				
				if(v[i][j] == 'v') {
					w++;
					dfs(i,j);
				}
				else if(v[i][j] == 'o') {
					l++;
					dfs(i,j);
				}

				if(l > w) {
					lamb = lamb + l;
				}
				else if(w >= l){
					wolf = wolf + w;
				}
				l = 0;
				w = 0;
			}
		}
	}
	
	cout << lamb << ' ' << wolf;
	
	return 0;
}
