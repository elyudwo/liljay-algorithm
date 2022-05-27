#include <iostream>
#include <queue>

using namespace std;

int t,n,current_x,current_y,target_x,target_y;

int v[301][301];
int check[301][301];

int dx[] = {1,2,2,1,-1,-2,-2,-1};
int dy[] = {2,1,-1,-2,-2,-1,1,2};
void bfs(int x,int y) 
{
	queue<pair<int,int>> q;
	q.push({x,y});
	check[x][y] = true;
	
	while(!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if(a == target_x && b == target_y) {
			cout << v[a][b] << endl;
			break;
		}
		for(int i=0; i<8; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if(nx>=0 && ny>=0 && nx < n && ny < n && !check[nx][ny]) {
				q.push({nx,ny});
				check[nx][ny] = true;
				v[nx][ny] = v[a][b] + 1;
			}
		}
		
	}
	
}

void reset() 
{
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			check[i][j] = 0;
			v[i][j] = 0;
		}
	}
}

int main()
{
	cin >> t;
	for(int i=0; i<t; i++) {
		cin >> n;
		cin >> current_x >> current_y;
		cin >> target_x >> target_y;
		
		bfs(current_x,current_y);
		reset();
	}
	
	return 0;
}
