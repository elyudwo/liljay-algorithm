#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[1002];
int dp[1002][2];

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
		dp[i][0] = 1;
		dp[i][1] = 1;
	}	
}


void solve() {
	int answer = 1;

	
	for(int i=2; i<=n; i++) {
		for(int j=1; j<i; j++) {
			if(arr[i] > arr[j]) {
				dp[i][1] = max({dp[i][1], dp[j][0] + 1, dp[j][1] + 1});
			}
			else if(arr[i] < arr[j]) {
				dp[i][0] = max(dp[i][0], dp[j][0] + 1);
			}
			answer = max({answer , dp[i][0], dp[i][1]});
		}
	}	
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}