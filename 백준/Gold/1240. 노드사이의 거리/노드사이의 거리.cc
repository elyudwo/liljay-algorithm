#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<pair<int,int> > vec[1001];

void bfs(int a, int b) {
	int answer = 0;
	// 현재 노드, 현재까지의 가중치 
	queue<pair<int,int> > q;
	q.push({a,0});
	bool check[1001] = {false,};
	check[a] = true;
	
	while(!q.empty()) {
		int x = q.front().first;
		int weight = q.front().second;
		q.pop();
		
		if(x == b) {
			cout << weight << '\n';
			break;
		}
		
		for(int i=0; i<vec[x].size(); i++) {
			if(check[vec[x][i].first]) { continue; }
			check[vec[x][i].first] = true;
			q.push({vec[x][i].first, weight + vec[x][i].second});
		}
	}
}

void input() {
	cin >> n >> m;
	for(int i=0; i<n-1; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		vec[a].push_back({b,c});
		vec[b].push_back({a,c});
	}
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		bfs(a,b);
	}
}

int main() {
	input();
	
}