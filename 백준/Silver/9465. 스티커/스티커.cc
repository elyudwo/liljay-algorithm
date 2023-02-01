#include <iostream>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		int arr[2][100001];
		int dp[2][100001];
		int answer = -1;
		
		cin >> n;
		
		for(int i=0; i<2; i++) {
			for(int j=0; j<n; j++) {
				int tmp;
				cin >> tmp;
				arr[i][j] = tmp;
			}
		}
		
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];
		
		
		for(int i=1; i<n; i++) {
			if(i == 1) {
				dp[0][1] = arr[1][0] + arr[0][1];
				dp[1][1] = arr[1][1] + arr[0][0];
				continue;
			}
			dp[0][i] = max(arr[0][i] + dp[1][i-1], arr[0][i] + dp[0][i-2]);
			dp[0][i] = max(dp[0][i], arr[0][i] + dp[1][i-2]);
			
			dp[1][i] = max(arr[1][i] + dp[0][i-1], arr[1][i] + dp[1][i-2]);
			dp[1][i] = max(dp[1][i],arr[1][i] + dp[0][i-2]);
		}
		
		for(int i=0; i<2; i++) {
			for(int j=0; j<n; j++) {
				answer = max(answer, dp[i][j]);
			}
		}
		
		cout << answer << "\n";
	}
}