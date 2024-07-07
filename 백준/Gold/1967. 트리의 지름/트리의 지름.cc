#include <iostream>
#include <vector>

using namespace std;

vector<pair<int,int> > g[10001];
int edge = -1;
bool check[10002];
int answer = 0;
 
void dfs(int num, int len) {
	if(len > answer) {
		answer = len;
		edge = num;
	}
	
	check[num] = true;
	
	for(int i=0; i<g[num].size(); i++) {
		int x = g[num][i].first;
		int cost = g[num][i].second;
		
		if(check[x]) continue;
		dfs(x, len + cost);
	}
}

int main() {
	int n;
	cin >> n;
	
	for(int i=0; i<n-1; i++) {
		int a,b,c;
		cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	dfs(1, 0);
	for(int i=0; i<=n; i++) { check[i] = false; }
	
	dfs(edge, 0);
	cout << answer;
	
}