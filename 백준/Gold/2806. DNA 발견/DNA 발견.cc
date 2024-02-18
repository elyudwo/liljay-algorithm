#include <iostream>
#define INF 2000000000

using namespace std;

int n;
string str;
int dp[1000001][2];

void input() {
	cin >> n;
	cin >> str;
	
	for(int i=0; i<=1000000; i++) {
		for(int j=0; j<2; j++) {
			dp[i][j] = INF;
		}
	}
}

void checkFirst() {
	if(str[0] == 'A') {
		dp[0][0] = 0;
		dp[0][1] = 1;
		return;
	}
	dp[0][0] = 1;
	dp[0][1] = 0;
}

void print() {
	for(int i=0; i<n; i++) {
		cout << dp[i][0] << " " << dp[i][1] << endl;
	}
} 

void solve() {
	checkFirst();
	
	for(int i=1; i<n; i++) {
		if(str[i] == 'A') {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1] + 1);
			dp[i][1] = min(dp[i-1][1] + 1, dp[i-1][0] + 1);
			continue;
		}
		dp[i][0] = min(dp[i-1][0] + 1, dp[i-1][1] + 1);
		dp[i][1] = min(dp[i-1][1], dp[i-1][0] + 1);
	}
	
//	print();
	
	cout << min(dp[n-1][0], dp[n-1][1] + 1);
}

int main() {
	input();
	solve();
	
}