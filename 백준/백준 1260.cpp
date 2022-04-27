#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> d[1001];

int c1[10001];
int bf[10001];

void dfs(int n)
{
	if(c1[n])	return;
	c1[n] = true;
	cout << n << ' ';
	for(int i=0; i < d[n].size(); i++) {
		int y = d[n][i];
		dfs(y);
	}
}

void bfs(int n) 
{
	queue<int> q;
	q.push(n);
	bf[n] = true;
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		cout << x << ' ';
		for(int i=0; i<d[x].size(); i++) {
			int y = d[x][i];
			if(!bf[y]) {
				q.push(y);
				bf[y] = true;
			}
		}
	}
}

int main(void)
{
	
	int n, m, v;
	cin >> n >> m >> v;
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		d[a].push_back(b);
		d[b].push_back(a);
	}
	
	for(int i=1; i<=n; i++) {
		sort(d[i].begin(),d[i].end());
	}
	
	dfs(v);
	cout << endl;
	bfs(v);
	
	return 0;
}
