#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int a,b,n,m;
vector<int> vec[1001];
bool check[1001];

void input() {
	cin >> a >> b;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int tmp1,tmp2;
		cin >> tmp1 >> tmp2;
		vec[tmp1].push_back(tmp2);
		vec[tmp2].push_back(tmp1); 
	}
}

void bfs() {
	queue<pair<int,int> > q;
	q.push({a,0});
	check[a] = true;
	
	while(!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		if(x == b) {
			cout << cnt;
			return;
		}
		
		for(int i=0; i<vec[x].size(); i++) {
			int nx = vec[x][i];
			if(check[nx]) { continue; }
			check[nx] = true;
			q.push({nx,cnt+1});
		}
	}
	cout << "-1";
}

void solve() {
	bfs();
}

int main() {
	input();
	solve();
	
}