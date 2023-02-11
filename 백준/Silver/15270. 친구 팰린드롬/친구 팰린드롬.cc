#include <iostream>
#include <vector>

using namespace std;

bool check[21];
vector<pair<int,int> > vec;
int answer = 1;
int n,m;

void input() {
	
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		vec.push_back({a,b});
	}
}

void dfs(int cnt,int index) {
	if(cnt < n) {
		answer = max(answer,cnt + 1);
	} 
	else {
		answer = max(answer,cnt);
	}
	
	for(int i=index; i<vec.size(); i++) {
		int a = vec[i].first;
		int b = vec[i].second;
		if(check[a] || check[b]) { continue; }
		check[a] = true;
		check[b] = true;
		dfs(cnt+2,i);
		check[a] = false;
		check[b] = false;
	}
}

void solve() {
	dfs(0,0);
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}