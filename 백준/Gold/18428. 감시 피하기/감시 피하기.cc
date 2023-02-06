#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int v[7][7];
bool check[36];
vector <pair <int,int> > dis,t;
int n;
int lee = 0;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool last_check;

bool c(int x,int y) 
{
	for(int i=0; i<4; i++) {
		int nx = x;
		int ny = y;
		while(nx>=1 && ny>=1 && nx<=n && ny<=n) {
			if(v[nx][ny] == 3)	break;
			if(v[nx][ny] == 1)	return false;
			nx = nx + dx[i];
			ny = ny + dy[i];
		}
	}
	return true;
	
}

void dfs(int x,int cnt) 
{
	if(cnt == 3) {
		for(auto lee : t) {
			if(!c(lee.first,lee.second)) {
				return;
			}
		}
		cout << "YES";
		exit(0);
	}
	
	for(int i=x; i<dis.size(); i++) {
		v[dis[i].first][dis[i].second] = 3;
		dfs(i+1,cnt+1);
		v[dis[i].first][dis[i].second] = 0;
	}
	
}

int main(void)
{
	cin >> n;
	// X = 0, S = 1, T = 2, O = 3
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			char a;
			cin >> a;
			if(a == 'X') {
				v[i][j] = 0;
				dis.push_back({i,j});
			}
			else if(a == 'S') {
				v[i][j] = 1;
			}
			else if(a == 'T') {
				v[i][j] = 2;
				t.push_back({i,j});
			}
		}
	}
	
	
	dfs(0,0);
	
	cout << "NO";
	
	return 0;
}