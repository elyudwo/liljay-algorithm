#include <iostream>
#include <vector> 
#include <queue>
#include <algorithm>

using namespace std;

int n, m;
vector<int> vec[102];
vector<pair<int,int> > rem;
bool check[102];

void input() {
	cin >> n >> m;	

	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
}

int bfs(int user) {
	queue<pair<int,int> > q;
	q.push({user, 0});
	int sum = 0;
	
	while(!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		sum += cnt;
		q.pop();
		
		
		for(int i=0; i<vec[x].size(); i++) {
			int nx = vec[x][i];
			if(check[nx]) continue;
			check[nx] = true;
			q.push({nx, cnt + 1});
		}
	}
	
	return sum;
}

void init() {
	for(int i=0; i<=100; i++) {
		check[i] = false;
	}
}

void solve() {
	for(int i=1; i<=n; i++) {
		int result = bfs(i);
		rem.push_back({result, i});
		init();
	}
	
	sort(rem.begin(), rem.end());
	
	cout << rem[0].second;
}

int main() {
	input();
	solve();
	
}