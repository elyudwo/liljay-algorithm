#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,k,l;
vector<pair<int,char> > change;
queue<pair<int,int> > qu;

int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
int fragment = 0;
bool apple[101][101];
int tail_x = 0;
int tail_y = 0;

int v[101][101];
int result;

void input() {
	cin >> n;
	cin >> k;
	for(int i=0; i<k; i++) {
		int x,y;
		cin >> x >> y;
		v[x][y] = 1;
	}
	
	cin >> l;
	for(int i=0; i<l; i++) {
		char c;
		int x;
		cin >> x >> c;
		change.push_back({x,c});
	}
}

void rotate(char c) {
	if(c == 'D') {
		fragment = (fragment + 1) % 4;
	}
	else if(c == 'L') {
		fragment = (fragment - 1);
		if(fragment == -1) {
			fragment = 3;
		}
	}
}

void solve() {
	// x,y ´Â head ÀÇ ÁÂÇ¥
	int x = 1;
	int y = 1;
	int time = 0;
	
	while(1) {
		for(int i=0; i<change.size(); i++) {
			if(change[i].first == time) {
				rotate(change[i].second);
			}
		}
		int nx = x + dx[fragment];
		int ny = y + dy[fragment];
		if(nx < 1 || nx > n || ny < 1 || ny > n || v[nx][ny] == 2) {
			result = time+1;
			break;
		}
		if(v[nx][ny] == 1 && !apple[nx][ny]) {
			apple[nx][ny] = true;
			v[x][y] = 2;
			qu.push({x,y});
		}
		else {
			if(!qu.empty()) {
				v[qu.front().first][qu.front().second] = 0;
				qu.pop();
				qu.push({x,y});
				v[x][y] = 2;
			}
		}
		time++;
		x = nx;
		y = ny;
	}
}

int main() {
	input();	
	solve();
	
	cout << result;
}
