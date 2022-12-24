#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
int n,m,k,x,a,b;
int check[300001];
bool c[300001];
vector<int> vec[300001];

void input() {
	cin >> n >> m >> k >> x;
	for(int i=0; i<m; i++) {
		cin >> a >> b;
		vec[a].push_back(b);
	}
	
	for(int i=1; i<=300000; i++) { check[i] = 9999999; }
}

void bfs() {
	queue<pair<int,int> > q;
	q.push({x,0});
	check[x] = 0;
	
	while(!q.empty()) {
		int nx = q.front().first;
		int cnt = q.front().second;
		q.pop(); 
		check[nx] = min(check[nx],cnt);
		
		for(int i=0; i<vec[nx].size(); i++) {
			if(c[vec[nx][i]])	continue;
			c[vec[nx][i]] = true;
			q.push({vec[nx][i],cnt+1});
		}
	}
}

void solve() {
	bfs();
	for(int i=0; i<=300000; i++) {
		if(check[i] == k) { answer.push_back(i); }
	}
	
	if(answer.size() == 0) {
		cout << "-1";
		return;
	}
	
	for(int i=0; i<answer.size(); i++) {
		cout << answer[i] << endl;	
	}
}


int main() {
	input();
	solve();	
	
}
