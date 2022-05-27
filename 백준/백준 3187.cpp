#include <iostream>

using namespace std;

string str[251];
bool visit[251][251];

int r,c;
int wolf = 0;
int lamb = 0;

int max_wolf,max_lamb = 0;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dfs(int x,int y) 
{
	if(visit[x][y])	return;
	visit[x][y] = true;
	
	if(str[x][y] == 'k') {
		lamb++;
	}
	else if(str[x][y] == 'v') {
		wolf++;
	}
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
		if(str[nx][ny] == '#')	continue;
		if(!visit[nx][ny] && (str[nx][ny] == '.' || str[nx][ny] == 'k' || str[nx][ny] == 'v')) {
			if(str[nx][ny] == '.') {
				dfs(nx,ny);
			}
			else if(str[nx][ny] == 'k') {
				dfs(nx,ny);
			}
			else if(str[nx][ny] == 'v') {
				dfs(nx,ny);
			}
		}
	}
}

int main(void)
{
	cin >> r >> c;
	for(int i=0; i<r; i++) {
		cin >> str[i];
	}
	
	for(int i=0; i<r; i++) {
		for(int j=0; j<c; j++) {
			if(!visit[i][j] &&(str[i][j] == 'k' || str[i][j] == 'v')) {
				dfs(i,j);
			}
			if(wolf >= lamb) {
				max_wolf = max_wolf + wolf;
			}
			else if(wolf < lamb) {
				max_lamb = max_lamb + lamb;
			}
			wolf = 0;
			lamb = 0;
		}
	}	
	
	cout << max_lamb << " " << max_wolf; 
	
	return 0;
}
