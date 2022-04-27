#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

int m[100][100];
bool c[100][100];

int cnt[100];
int lee = 0;
int m1,n,k;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x,int y) {
	if(c[x][y])	return;
	c[x][y] = true;
	cnt[lee]++;
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || nx >= m1 || ny < 0 || ny >= n) continue;
		if(m[nx][ny] == 1 && !c[nx][ny]) {
			dfs(nx,ny);
		}
	}
}

int main(void) 
{
	
	cin >> m1 >> n >> k;
	for(int i=0; i<m1; i++) {
		for(int j=0; j<n; j++) {
			m[i][j] = 1;
		}
	}
	
	for(int i=0; i<k; i++) {
		int a,b,c,d;
		cin >> a >> b >> c >> d;
		
		for(int j=c-1; j>=a; j--) {
			for(int y=d-1; y>=b; y--) {
				m[y][j] = 0;
			}
		}
	}
	
	int t = 0;
	
	for(int i=0; i<m1; i++) {
		for(int j=0; j<n; j++) {
			if(!c[i][j] && m[i][j] == 1) {
				dfs(i,j);
				t++;
				lee++;
			}
		}
	}
	
	
	sort(cnt,cnt+100);
	
	cout << t << endl;
	
	for(int i=0; i<100; i++) {
		if(cnt[i] == 0)
			continue;
		else
			cout << cnt[i] << ' ';
	}
	
	return 0;
}
