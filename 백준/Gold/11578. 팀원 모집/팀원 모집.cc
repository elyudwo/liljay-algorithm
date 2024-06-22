#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<int> vec[11];

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=m; i++) {
		int n;
		cin >> n;
		for(int j=0; j<n; j++) {
			int tmp;
			cin >> tmp;
			
			vec[i].push_back(tmp);
		}
	}
}	

vector<int> team;
bool check = false;

bool checkAll() {
	bool c[11] = {false,};
	for(int idx : team) {
		for(int num : vec[idx]) {
			c[num] = true;
		}
	}
	
	for(int i=1; i<=n; i++) {
		if(!c[i]) return false;
	}
	
	return true;
}

void dfs(int n, int idx) {
	if(team.size() == n) {
		if(checkAll()) { check = true; }
		return;
	}
	
	for(int i=idx; i<=m; i++) {
		team.push_back(i);
		dfs(n, idx + 1);
		team.pop_back();
	}
}
	
void solve() {
	for(int i=0; i<=m; i++) {
		dfs(i, 1);
		if(check) {
			cout << i;
			return;
		}
	}
	cout << "-1";
}

int main() {
	input();
	solve();
	
}