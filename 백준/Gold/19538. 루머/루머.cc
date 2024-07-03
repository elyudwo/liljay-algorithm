#include <iostream>
#include <vector>
#include <queue>
#define INF 2e9
using namespace std;

int n, m;
vector<int> v[200001];
int t[200001];
bool check[200001];

void bfs() {
	queue<pair<int,int> > q;
	cin >> m;
	
	for(int i=1; i<=n; i++) {
		t[i] = INF;
	}
	
	
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		q.push({tmp, 1});
		t[tmp] = 1;
	}
	
	while(!q.empty()) {
		int x = q.front().first;
		int minute = q.front().second;
		
		q.pop();
		t[x] = min(minute, t[x]);
		
		for(int i=0; i<v[x].size(); i++) {
			int nx = v[x][i];
			if(t[nx] != INF) continue;
			
			int believe = 0;
			for(int j=0; j<v[nx].size(); j++) {
				if(t[v[nx][j]] != INF) { believe++; }
			}
			
			int cnt = 0;
			if(v[nx].size() % 2 == 1) { cnt = v[nx].size() / 2 + 1; }
			else { cnt = v[nx].size() / 2; }
			
			if(believe >= cnt) { q.push({nx, minute + 1}); }
		}
	}
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	
	for(int i=1; i<=n; i++) {
		while(1) {
			int tmp;
			cin >> tmp;
			if(tmp == 0) break;
			v[i].push_back(tmp);
		}
	}
	bfs();
	
	// time에서 하나씩 빼줘야함 
	for(int i=1; i<=n; i++) {
		if(t[i] == INF) {
			cout << "-1 ";
			continue;
		}
		cout << t[i] - 1 << " ";
	}
}