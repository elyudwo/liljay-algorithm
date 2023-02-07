#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,m;
vector<int> vec[2001];
bool check[2001] = {false,};
int answer = 0;

void input() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
}

void dfs(int index,int cnt) {
	if(cnt == 4) {
		answer = 1;
		return;
	}
	
	for(int i=0; i<vec[index].size(); i++) {
		if(check[vec[index][i]]) { continue; }
		check[vec[index][i]] = true;
		dfs(vec[index][i], cnt+1);
		check[vec[index][i]] = false;
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		check[i] = true;
		dfs(i,0);
		check[i] = false;
		
		if(answer == 1) {
			break;
		}
	}
	cout << answer;
}

int main() {
	input();
	solve();
	
}