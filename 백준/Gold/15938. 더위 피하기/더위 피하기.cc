#include <iostream>
#include <vector>
#include <cmath>


using namespace std;

typedef long long ll;

int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
ll MOD = 1e9 + 7;
bool visit[201][401][401];
bool obs[401][401];
vector<pair<int,int> > vec[201];
ll arr[201][401][401];

int main() {
	int sx,sy,ex,ey,t,n;
	cin >> sx >> sy;
	cin >> t;
	
	cin >> ex >> ey;
	
	if(200 + ex - sx < 0 || 200 + ex - sx > 400 || 
	    200 + ey - sy < 0 || 200 + ey - sy > 400) {
		cout << "0";
		return 0;
	}
	
	ex = 200 + ex - sx;
	ey = 200 + ey - sy; 
	
	cin >> n;
	while(n--) {
		int x,y;
		cin >> x >> y;
		if(200 + x - sx >= 0 && 200 + x - sx <= 400 && 200 + y - sy >= 0 
		&& 200 + y - sy <= 400) {
			obs[200 + x - sx][200 + y - sy] = true;
		}
	}
	
	sx = 200;
	sy = 200;
	vec[0].push_back({sx, sy});
	visit[0][sx][sy] = true;
	arr[0][sx][sy] = 1;
	
	for(int i=0; i<t; i++) {
	    visit[i][ex][ey] = true;
	}
	
	
	for(int i=0; i<t; i++) {
		for(pair<int,int> p : vec[i]) {
			for(int j=0; j<4; j++) {
				int nx = dx[j] + p.first;
				int ny = dy[j] + p.second;
				
				if(nx < 0 || ny < 0 || nx > 400 || ny > 400 || obs[nx][ny]) continue;
				arr[i+1][nx][ny] += arr[i][p.first][p.second];
				arr[i+1][nx][ny] %= MOD;
				
				if(!visit[i+1][nx][ny]) {
					vec[i+1].push_back({nx, ny});
					visit[i+1][nx][ny] = true;
				}
			}
		}
	}
	
	ll answer = 0;
	for(int i=0; i<=t; i++) {
		answer = (answer + arr[i][ex][ey]);
		answer = answer % MOD;
	}
	
	cout << answer;
	
}