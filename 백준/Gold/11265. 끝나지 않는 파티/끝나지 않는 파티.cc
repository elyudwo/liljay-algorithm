#include <iostream>
#include <queue>
#define INF 2e9
using namespace std;

typedef long long ll;

int n, m;
int party[501][501];
int time_arr[501][501];

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			cin >> party[i][j];
			time_arr[i][j] = INF;
		}
	}
	
}

void dijkstra(int num) {
	priority_queue<pair<int,int> > pq;
	pq.push({0, num});
	time_arr[num][num] = 0;
	
	while(!pq.empty()) {
		int x = pq.top().second;
		int dist = -pq.top().first;
		pq.pop();
	
		if(time_arr[num][x] < dist) { continue; }
	
		for(int i=1; i<=n; i++) {
			if(i == x) continue;
			int cost = dist + party[x][i];
			
			if(cost < time_arr[num][i]) {
				time_arr[num][i] = cost;
				pq.push({-cost, i});
			}
		}
	}
		
}

void solve() {
	for(int i=1; i<=n; i++) {
		dijkstra(i);
	}
	
	for(int i=0; i<m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		if(time_arr[a][b] <= c) { 
			cout << "Enjoy other party\n";
			continue;
		}
		cout << "Stay here\n";
	}
}

int main() {
	input();
	solve();
	
}