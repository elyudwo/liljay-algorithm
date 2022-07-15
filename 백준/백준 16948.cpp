#include <iostream>
#include <queue>
using namespace std;
int n,r1,c1,r2,c2;

bool visited[201][201];
int distance[201][201];
int v[201][201];

int dx[] = {-2,-2,0,0,2,2};
int dy[] = {-1,1,-2,2,-1,1};

void bfs(int x,int y) 
{
	queue<pair<int,int>> q;
	q.push({x,y});
	visited[x][y] = true;
	distance[x][y] = 0;
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		
		for(int i=0; i<6; i++) {
			int nx = dx[i] + x;
			int ny = dy[i] + y;
			
			if(nx < 0 || ny < 0 || nx >= n || ny >= n) {
				continue;
			}
			if(!visited[nx][ny]) {
				distance[nx][ny] = distance[x][y] + 1;
				visited[nx][ny] = true;
				q.push({nx,ny});
			}
			
		}
		
	}
}

int main(void)
{
	cin >> n;
	cin >> r1 >> c1 >> r2 >> c2;
	
	bfs(r1,c1);
	
	if(distance[r2][c2] == 0) {
		cout << -1;
	}
	else {
		cout << distance[r2][c2];
	}
	
	return 0;
}
