#include <iostream>
#include <string>
#include <queue>
using namespace std;

string v[6];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int r,c,k;
int result = 0;
bool check[6][6];
void dfs(int x,int y,int cnt) 
{
	if(cnt == k && x == 0 && y == c-1) {
		result++;
		return;
	}
	if(cnt > k) return;
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if(nx < 0 || ny < 0 || nx >= r || ny >= c)	continue;
		if(v[nx][ny] == '.' && !check[nx][ny]) {
			check[nx][ny] = true;
			dfs(nx,ny,cnt+1);
			check[nx][ny] = false;
		}
	}
	
}

int main(void)
{
	cin >> r >> c >> k;
	
	for(int i=0; i<r; i++) {
		cin >> v[i];
	}
	check[r-1][0] = true;
	dfs(r-1,0,1);
	cout << result;
	
	return 0;
}
