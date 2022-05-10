#include <iostream>
#include <cstring>

using namespace std;

int t,h,w;
string v[100];
bool c[100][100];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dfs(int x,int y) 
{
	if(c[x][y])	return;
	c[x][y] = true;
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
		if(!c[nx][ny] && v[nx][ny] == '#')
			dfs(nx,ny);
		
	}
}



int main(void)
{
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> h >> w;
		for(int j=0; j<h; j++) {
			cin >> v[j];
		}
		
		int cnt = 0;
		
		for(int j=0; j<h; j++) {
			for(int k=0; k<w; k++) {
				if(!c[j][k] && v[j][k] == '#') {
					dfs(j,k);
					cnt++;
				}
			}
		}
		
		cout << cnt << endl;
		
		for(int j=0; j<h; j++) {
			for(int k=0; k<w; k++) {
				c[j][k] = false;
				v[j][k] = '.';
			}
		} 
		
	}
	
	
	
	return 0;
}
