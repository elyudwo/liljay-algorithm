#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

char a[101][101];
bool check[101][101] = {false};
	
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};
int n;
	
void dfs(int x, int y) 
{
	check[x][y] = true;
	for(int i=0; i<4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
		if (!check[nx][ny] && a[x][y] == a[nx][ny]) {
			dfs(nx, ny);
		}
	}
}


int main(void)
{
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> a[i][j];
		}
	}
	
	int normal = 0;
	int abnormal = 0;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(check[i][j] == false) {
				dfs(i,j);
				normal++;
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(a[i][j] == 'G') {
				a[i][j] = 'R';
			}
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			check[i][j] = false;
		}
	}
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(check[i][j] == false) {
				dfs(i,j);
				abnormal++;
			}
		}
	}
	
	cout << normal << ' ' << abnormal;

	
	return 0;
}
