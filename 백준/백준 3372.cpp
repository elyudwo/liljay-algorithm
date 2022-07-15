#include <iostream>

using namespace std;

int v[101][101];
unsigned long long int dp[101][101];
int main(void)
{
	int n;
	cin >> n;
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> v[i][j];
		}
	}
	
	if(v[0][0] == 0) {
		cout << "0";
		return 0;
	}
	
	dp[0][0] = 1;
	
	
	
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			int nx = i + v[i][j];
			int ny = j + v[i][j];
			if(dp[i][j] == 0 || (i == n-1 && j == n-1))	continue;
			if(nx < n)	{
				if(v[nx][j] == 0 && ( (nx == n-1) && (j == n-1))) {
					dp[nx][j] = dp[i][j] + dp[nx][j];
				}
				else if(v[nx][j] == 0 ) continue;
				else {
					dp[nx][j] = dp[i][j] + dp[nx][j];	
				}
			}
			if(ny < n) {
				if(v[i][ny] == 0 && ( (ny == n-1) && (i == n-1))) {
					dp[i][ny] = dp[i][j] + dp[i][ny];
				}
				else if(v[i][ny] == 0 ) continue;
				else {
					dp[i][ny] = dp[i][j] + dp[i][ny];	
				}
				
			}
		}
	}
	
	cout << dp[n-1][n-1];
	
	return 0;
}
