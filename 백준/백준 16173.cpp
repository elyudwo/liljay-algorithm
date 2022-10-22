#include <iostream>
#include <queue>
using namespace std;

int v[4][4];
bool check[4][4];
int n;
bool c = false;

void bfs()
{
	queue<pair<int,int> > q;
	q.push({1,1});
	
	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		check[x][y] = true;
		q.pop();
		
		if(v[x][y] == -1) {
			c = true;
			break;
		}
		
		if(x + v[x][y] <= n) {
			if(!check[x+v[x][y]][y]) {
				q.push({x + v[x][y],y});
			}
		}
		if(y + v[x][y] <= n) {
			if(!check[x][y+v[x][y]]) {
				q.push({x,y+v[x][y]});
			}
		}
	}
}


int main(void)
{
	cin >> n;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> v[i][j];
		}
	}
	
	bfs();
	
	if(c) {
		cout << "HaruHaru";
	}
	else {
		cout << "Hing";
	}
	
	
	return 0;
}
