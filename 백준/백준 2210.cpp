#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int v[5][5];

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visit[1000000];

int answer = 0;

void dfs(int x,int y,int hello,int cnt)
{
	if(cnt == 6) {
		if(!visit[hello]) {
			visit[hello] = true;
			answer = answer + 1;
		}
		return;
	}
	
	for(int i=0; i<4; i++) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		
		if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
		
		dfs(nx,ny,hello * 10 + v[nx][ny],cnt+1);
	}
}


int main(void)
{
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			cin >> v[i][j];
		}
	}
	
	
	int cnt = 1;

	string str;
	for(int i=0; i<5; i++) {
		for(int j=0; j<5; j++) {
			dfs(i,j,v[i][j],1);
			
		}
	}
	
	
	cout << answer;
	
	return 0;
}
