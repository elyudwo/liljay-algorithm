#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> g[100010];
bool check[100010] = {false, };
int answer = 0;
int edge = -1;

void dfs(int num, int len) {
	if(answer < len) {
		edge = num;
		answer = len;
	}
	check[num] = true;
	
	
	for(int i=0; i<g[num].size(); i++) {
		int x = g[num][i];
		if(check[x]) continue;
		dfs(x, len + 1);
	}
}

int main() {
	cin >> n;
	
	for(int i=0; i<n-1; i++) {
		int a,b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int root = 1;
	for(int i=1; i<=n; i++) {
		if(g[i].size() > 1) {
			root = i;
			break;
		}
	}
	
	dfs(root, 0);
	for(int i=0; i<=n; i++) { check[i] = false; }	
	answer = 0;
	dfs(edge, 0);
	
	cout << (answer + 1) / 2;
}