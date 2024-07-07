#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;

int n,m;
vector<pair<ll,ll> > g[100001];
ll answer = 0;
ll s,e;

bool can(ll weight) {
	bool visit[100001] = {false,};
	queue<int> q;
	q.push(s);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		if(x == e) {
			answer = max(answer, weight);
			return true;
		}
		
		for(int i=0; i<g[x].size(); i++) {
			int nx = g[x][i].first;
			int cost = g[x][i].second;
			if(visit[nx] || cost < weight) continue;
			visit[nx] = true;
			q.push(nx);
		}
	}
	
	return false;
}

int main() {
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b,c});
		g[b].push_back({a,c});
	}
	
	cin >> s >> e;
	
	ll left = 0;
	ll right = 1e9;
	
	while(left <= right) {
		ll mid = (left + right) / 2;
		
		if(can(mid)) {
			left = mid + 1;
			continue;
		}
		right = mid - 1;
	}
	
	cout << answer;
}