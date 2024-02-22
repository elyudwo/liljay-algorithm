#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, k;
vector<int> vec;
int dp[10002];

void input() {
	cin >> n >> k;
	for(int i=0; i<n; i++) {
		int tmp; cin >> tmp;
		if(tmp > k) { continue; }
		vec.push_back(tmp);
	}
	sort(vec.begin(), vec.end());
}

void solve() {
	for(int i=0; i<vec.size(); i++) {
		int x = vec[i];
		if(x > k) continue;
		dp[x] += 1;
		
		for(int j=x+1; j<=k; j++) {
			dp[j] += dp[j-x];
		}
	}
	
	cout << dp[k];
}

int main() {
	input();
	solve();
	
}