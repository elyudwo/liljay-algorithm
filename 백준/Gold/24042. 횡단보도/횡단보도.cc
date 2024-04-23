#include <iostream>
#include <queue>
#define INF 8000000000000


using namespace std;

typedef long long ll;
int n, m;
vector<pair<ll,ll> > graph[100001];
ll arr[100001];

void input() {
	cin >> n >> m;
	
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back({b, i});
		graph[b].push_back({a, i});
	}
	
	for(int i=1; i<=n; i++) {
		arr[i] = INF;
	}
}

void dijkstra() {
	arr[1] = 0;
	
	// 시간, 위치 
	priority_queue<pair<ll,ll> > q;
	q.push({0, 1});
// 	cout << "로깅 시작 \n";
	while(!q.empty()) {
		ll t = -q.top().first;
		ll x = q.top().second;
		q.pop();
// 		cout << t << " " << x << '\n';
		
		if(arr[x] < t) { continue; }
		
		for(pair<int,int> p : graph[x]) {
			ll go_time = 0;
			ll t_tmp = t % m;
			
			if(t_tmp > p.second) { go_time = m - t_tmp + p.second; }
			else { go_time = p.second - t_tmp; }
			
			// 횡단보도 건너가는 시간
			go_time++;
			
			if(t + go_time < arr[p.first]) {
				arr[p.first] = t + go_time;
				q.push({-(t + go_time), p.first});
			}
		}
	}
}

void solve() {
	dijkstra();	
	
	cout << arr[n];
}

int main() {
	input();
	solve();
} 