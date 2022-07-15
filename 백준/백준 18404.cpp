#include <iostream>
#include <queue>
#include <tuple>

using namespace std;

int v[501][501];
int a,b;
bool check[501][501];
int path[501][501];
int result[1001];
int lee = 0;
int dy[] = {-1,1,-2,2,-2,2,-1,1};
int dx[] = {-2,-2,-1,-1,1,1,2,2};
int n,m;

void bfs(int x,int y) 
{
	check[x][y] = true;
	path[x][y] = 0;
	queue<pair<int,int>>q;
	q.push({x,y});

	while(!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		q.pop();
		
		for(int i=0; i<8; i++) {
			int nx = x1 + dx[i];
			int ny = y1 + dy[i];
			
			if(nx <= 0 || ny <= 0 || nx > n || ny > n) {
				continue;
			}
			
			if(!check[nx][ny]) {
			    path[nx][ny] = path[x1][y1] + 1;
				check[nx][ny] = true;
				q.push({nx,ny});
			}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	
	int x,y;
	cin >> x >> y;
	
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		bfs(x,y);
		result[i] = path[a][b];
		
	}
	
	for(int i=0; i<m; i++) {
		cout << result[i] << " ";
	}
	
	return 0;
}
