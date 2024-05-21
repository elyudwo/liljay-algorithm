#include <iostream>

using namespace std;

int n;
int arr[1002];
int dp[1002];

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	for(int i=2; i<=n; i++)	{
		int max_value = arr[i], min_value = arr[i];
		
		for(int j=i-1; j>=0; j--) {
			max_value = max(max_value, arr[j+1]);
			min_value = min(min_value, arr[j+1]);
			
			dp[i] = max(dp[i], dp[j] + max_value - min_value);
		}
	}
	
	cout << dp[n];
}

int main() {
	input();
	solve();
	
}