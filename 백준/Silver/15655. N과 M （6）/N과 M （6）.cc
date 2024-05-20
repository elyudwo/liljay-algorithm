#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<int> rem;
vector<int> vec;

void input() {
	cin >> n >> m;
	
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
	
	sort(vec.begin(), vec.end());
}

void dfs(int idx) {
	if(rem.size() == m) {
		for(int tmp : rem) {
			cout << tmp << " ";
		}
		cout << '\n';
		return;
	}
	
	for(int i=idx; i<n; i++) {
		rem.push_back(vec[i]);
		dfs(i + 1);
		rem.pop_back();
	}
}

void solve() {
	dfs(0);
}

int main() {
	input();
	solve();
	
}