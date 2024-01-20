#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[100002];
bool visit[100002];
int n, m, s;

void input() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		vec[a].push_back(b);
	}
	
	cin >> s;
	for(int i=0; i<s; i++) {
		int tmp;
		cin >> tmp;
		visit[tmp] = true;
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	visit[1] = true;
	
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		if(vec[x].size() == 0) {
			cout << "yes";
			return;
		}
		
		for(int i=0; i<vec[x].size(); i++) {
			int nx = vec[x][i];
			
			if(visit[nx]) continue;
			q.push(nx);
			visit[nx] = true;
		}
	}
	
	cout << "Yes";
}

void solve() {
	if(visit[1]) {
		cout << "Yes";
		return;
	}
	
	bfs();
}

int main() {
	input();
	solve();
}