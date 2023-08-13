#include <iostream>
#include <vector>

using namespace std;

/*
1. 백트래킹
2. 모양 네가지 + 안 쓰는 경우 

*/ 

bool check[6][6];
int n,m;
int arr[6][6];
int answer = 0;
vector<pair<int,int> > vec[4];

void input() {
	cin >> n >> m;
	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			cin >> arr[i][j];
		}
	}
	
	vec[0].push_back({0,-1});
	vec[0].push_back({1,0});
	
	vec[1].push_back({-1,0});
	vec[1].push_back({0,-1});
	
	vec[2].push_back({-1,0});
	vec[2].push_back({0,1});
	
	vec[3].push_back({0,1});
	vec[3].push_back({1,0});
} 

void dfs(int x, int y, int sum) {
	answer = max(answer, sum);
	
	if(y == m) {
		x = x+1;
		y = 0;
	}
	if(x == n) { return; }
	
	if(!check[x][y]) {
		for(int i=0; i<4; i++) {
			int x1,y1,x2,y2;
			x1 = x + vec[i][0].first; y1 = y + vec[i][0].second;
			x2 = x + vec[i][1].first; y2 = y + vec[i][1].second;
			
			if(x1 < 0 || x2 < 0 || x1 >= n || x2 >= n || y1 >= m || y2 >= m || y1 < 0 || y2 < 0 ) continue;
			if(check[x1][y1] || check[x2][y2]) continue;
			
			check[x][y] = true;
			check[x1][y1] = true;
			check[x2][y2] = true;
			
			dfs(x,y+1,sum + arr[x][y] * 2 + arr[x1][y1] + arr[x2][y2]);
			
			check[x][y] = false;
			check[x1][y1] = false;
			check[x2][y2] = false;
		}
	}
	
	dfs(x, y+1, sum);
}

void solve() {
	dfs(0,0,0);
	cout << answer;
}


int main() {
	input();
	solve();
	
}