#include <iostream>

using namespace std;

typedef long long ll;

ll dp[31][31];

ll dfs(int w, int h) {
	if(w == 0) return 1;
	
	ll& tmp = dp[w][h];
	
	if(dp[w][h] != -1) return tmp; 
	
	tmp = dfs(w-1, h+1);
	
	if(h > 0) { tmp += dfs(w, h-1); }
	
	return tmp;
}

int main() {
	for(int i=0; i<=30; i++) {
		for(int j=0; j<=30; j++) {
			dp[i][j] = -1;
		}
	}
	
	
	while(1) {
		int n;
		cin >> n;
		if(n == 0) break;
		
		cout << dfs(n, 0) << '\n';
	}
	
	
}