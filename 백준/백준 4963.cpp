#include <iostream>
using namespace std;

int v[50][50];
int w,h;
bool c[50][50];
int dx[] = {0,0,-1,1,1,1,-1,-1};
int dy[] = {-1,1,0,0,1,-1,1,-1};



void dfs(int x,int y)
{
	if(c[x][y])	return;
	c[x][y] = true;
	
	for(int i=0; i<8; i++) {
		
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if (ny < 0 || nx < 0 || ny >= h || nx >= w)
            continue;
		if(!c[nx][ny] && v[nx][ny] == 1) {
			dfs(nx,ny);
		}	
	}
	
}

int main(void)
{

	while(1) {
		cin >> w >> h;
		
		if(w == 0 && h == 0) 
			break;
		
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				cin >> v[i][j];	 
			}
		}
		
		
		int cnt = 0;
		
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				if(!c[i][j] && v[i][j] == 1) {
					dfs(i,j);
					cnt++;
				}
			}
		}	
		
		
		
		cout << cnt << endl;
		
		cnt = 0;
		for(int i=0; i<h; i++) {
			for(int j=0; j<w; j++) {
				c[i][j] = false;
				v[i][j] = 0;
			}
		}
		
	}
	
	
	
	return 0;
}
