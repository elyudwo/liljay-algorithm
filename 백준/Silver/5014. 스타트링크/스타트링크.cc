#include <iostream>
#include <queue>
#define INF 1e9

using namespace std;

int f,s,g,u,d;
int dist[1000001];
int dx[2];

void input() {
	cin >> f >> s >> g >> u >> d;
	
	dx[0] = u;
	dx[1] = -d;
}

void bfs() {
	queue<pair<int,int> > q;
	q.push({s, 0});
	
	while(!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		if(x == g) { break; }
		
		for(int i=0; i<2; i++) {
			int nx = dx[i] + x;
			if(nx < 1 || nx > f || dist[nx] != INF) continue;
			dist[nx] = cnt + 1;
			q.push({nx, cnt + 1});
		}
	}
}

void solve() {
	if(s == g) {
		cout << "0";
		return;
	} 
	
	for(int i=1; i<=1000000; i++) {
		dist[i] = INF;
	}
	
	bfs();
	
	if(dist[g] == INF) {
		cout << "use the stairs";
		return;
	}
	cout << dist[g];
}

int main() {
	input();
	solve();
	
} 