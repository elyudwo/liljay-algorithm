#include <iostream>
#include <queue>
#define INF 200000000
using namespace std;

bool check[1010][1010];
int s;
int answer = INF;

void input() {
	cin >> s;
}

struct board {
	int x;
	int clip;
	int cnt;
};

void bfs() {
	queue<board> q;
	q.push({1,0,0});
	
	while(!q.empty()) {
		int x = q.front().x;
		int clip = q.front().clip;
		int cnt = q.front().cnt;
		
		//cout << x << " " << clip << " " << cnt << endl;
			
		if(x == s) {
			answer = cnt;
			break;
		}
		q.pop();
		
		// case 1 
		int nclip = x;
		if(!check[x][nclip]) {
			check[x][nclip] = true;
			q.push({x, nclip, cnt+1});	
		}
		
		int nx = x + clip;
		
		// case 2
		if(nx < 1002 && clip != 0 && !check[nx][clip]) {
			check[nx][clip] = true;
			q.push({nx, clip, cnt+1});
		}
		
		// case 3 
		if(x-1 > 0 && !check[x-1][clip]) {
			check[x-1][clip] = true;
			q.push({x-1, clip, cnt+1}); 
		}
		
	}
}

void solve() {
	bfs();
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}
