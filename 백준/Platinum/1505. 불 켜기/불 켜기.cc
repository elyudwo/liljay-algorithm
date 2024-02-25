#include <iostream>
#include <string>
#include <vector>
#define INF 200000000

using namespace std;

int n, m;
char c[12][12];
int dx[] = {0,0,0,-1,1,-1,-1,1,1};
int dy[] = {0,-1,1,0,0,-1,1,-1,1};
int dx_a[] = {-1,-1,-1};
int dy_a[] = {-1,0,1};

int answer = INF;
vector<int> vec;
 
void input() {
	cin >> n >> m;
	for(int i=1; i<=n; i++) {
		string str;
		cin >> str;
		
		for(int j=1; j<=m; j++) {
			c[i][j] = str[j-1];
		}
	}	
}

void calculate() {
	int cnt = 0;
	char rem[12][12];
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			rem[i][j] = c[i][j];
		}
	}
	
	for(int i=1; i<=m; i++) {
		if(vec[i-1]) {
			cnt++;
			for(int j=0; j<9; j++) {
				int nx = dx[j] + 1;
				int ny = dy[j] + i;
				
				if(rem[nx][ny] == '*') {
					rem[nx][ny] = '.';
					continue;
				}
				rem[nx][ny] = '*';
			}
		}
	}
	
	for(int i=m+1; i<=n+m-1; i++) {
		if(vec[i-1]) {
			cnt++;
			for(int j=0; j<9; j++) {
				int nx = dx[j] + i - m + 1;
				int ny = dy[j] + 1;
				
				if(rem[nx][ny] == '*') {
					rem[nx][ny] = '.';
					continue;
				}
				rem[nx][ny] = '*';
			}
		}
	}
	
	
	for(int i=2; i<=n; i++) {
		for(int j=2; j<=m; j++) {
			bool check = true;
			
			for(int k=0; k<1; k++) {
				int nx = dx_a[k] + i;
				int ny = dy_a[k] + j;
					
				if(nx < 1 || nx > n || ny < 1 || ny > m) { continue; }
				if(rem[nx][ny] == '*') { check = false; }
			}
			
			if(check) {
				cnt++;
				for(int k=0; k<9; k++) {
					int nx = dx[k] + i;
					int ny = dy[k] + j;
					
					if(nx < 1 || nx > n || ny < 1 || ny > m) { continue; }
					if(rem[nx][ny] == '*') {
						rem[nx][ny] = '.';
						continue;
					}
					rem[nx][ny] = '*';
				}
			}
		}
	}
	
	bool check = true;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			if(rem[i][j] == '.') {
				check = false;
			}
		}
	}

	if(check) {
		answer = min(answer, cnt);
	}
	
}

void dfs() {
	if(vec.size() == n+m-1) {
		calculate();
		return;
	}
	
	
	for(int i=0; i<2; i++) {
		vec.push_back(i);
		dfs();
		vec.pop_back();
	}
}

void solve() {
	dfs();
	
	if(answer == INF) {
		cout << "-1";
		return;
	}
	cout << answer;
}

int main() {
	input();
	solve();
	
}