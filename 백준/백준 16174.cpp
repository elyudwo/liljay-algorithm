#include <iostream>

using namespace std;

int n;
int v[65][65];
bool check[65][65];
bool lee;

int dx[] = {1,0};
int dy[] = {0,1};
void dfs(int x,int y) 
{
	if(check[x][y]) return;
	if(x == n-1 && y == n-1) {
		lee = true;
		return;
	}
	check[x][y] = true;
	
	for(int i=0; i<2; i++) {
		int nx = dx[i]*v[x][y] + x;
		int ny = dy[i]*v[x][y] + y;
		if(nx >= n || ny >= n || nx < 0 || ny < 0) continue;
		if(!check[nx][ny]) {
			dfs(nx,ny);
		}
	}
}

int main(void)
{
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> v[i][j];
		}
	}
	dfs(0,0);
	
	if(lee) {
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}
	
	return 0;
}
