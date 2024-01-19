#include <iostream>
#include <vector>
#include <set>

using namespace std;
#define INF 1e9
int n,m;
set<int> st;
vector<int> vec;
int dp[20005] = {0,};

void input() {
	cin >> n >> m;
	for(int i=0; i<20005; i++) {
		dp[i] = INF;
	}
	
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		
		vec.push_back(tmp);
		st.insert(tmp);
		dp[tmp] = 1;
	}
	
	for(int i=0; i<m; i++) {
		for(int j=i+1; j<m; j++) {
			st.insert(vec[i] + vec[j]);
			dp[vec[i] + vec[j]] = 1;
		}
	}
}

void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=i/2; j++) {
			if(dp[j] == INF || dp[i-j] == INF) { continue; }
//			cout << i << " " << "HI" << endl;
			dp[i] = min(dp[i], dp[j] + dp[i - j]);
		}
	}
	
//	for(int i=1; i<=n; i++) {
//		cout << dp[i] << " ";
//	} 
	
	if(dp[n] == INF) {
		cout << "-1";
		return;
	}
	
	cout << dp[n];
}

int main() {
	input();
	solve();
	
}