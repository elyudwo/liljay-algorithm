#include <iostream>
#include <queue>

using namespace std;

#define INF 1e9

int v,e;
int start;
vector<pair<int,int> > vec[20001];
int d[20002];

void input() {
	cin >> v >> e;
	cin >> start;
	
	while(e--) {
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});
	}
	
	fill(d, d + 20001, INF);
}

void dijkstra() {
	priority_queue<pair<int,int>> pq;
	
	pq.push({0, start});
	d[start] = 0;
	
	while(!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		
		if(d[now] < dist) continue;
		
		for(int i=0; i<vec[now].size(); i++) {
			int cost = dist + vec[now][i].second;
			
			if(cost < d[vec[now][i].first]) {
				d[vec[now][i].first] = cost;
				pq.push({-cost, vec[now][i].first});
			}
		}
	}
}

void solve() {
	dijkstra();
	
	for(int i=1; i<=v; i++) {
		if(d[i] == 1e9) {
			cout << "INF" << '\n';
			continue;
		}
		
		cout << d[i] << '\n';
	}
}

int main() {
	input();
	solve();
	
}