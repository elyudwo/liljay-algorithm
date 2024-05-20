#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int n, x, y;
ll answer = 0;
bool use[15];
bool check[26];
vector<int> vec;

void input() {
	cin >> n >> x >> y;
}

void dfs(int cnt) {
	if(cnt == n * 2 + 1) {
		answer++;
		return;
	}
	
	if(!check[cnt]) {
		for(int i=1; i<=n; i++) {
			if(use[i] || check[cnt] || check[cnt + 1 + i]) continue;
			use[i] = true;
			check[cnt] = true;
			check[cnt + 1 + i] = true;
			dfs(cnt + 1);
			use[i] = false;
			check[cnt] = false;
			check[cnt + 1 + i] = false;
		}	
	}
	else {
		dfs(cnt + 1);
	}
	
}

void solve() {
	use[y - x - 1] = true;
	check[x] = true;
	check[y] = true;
	dfs(1);
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}