#include <iostream>
#include <queue>

int v[101][101];

using namespace std;
int dx[] = {0,1};
int dy[] = {1,0};
int n;
long long result = 0;

int main(void)
{
	cin >> n;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> v[i][j];
		}
	}
	
	long long dp[101][101];
 	dp[0][0] = 1;
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(v[i][j] == 0) continue;
			
			int nx = i + v[i][j] * dx[i];
			int ny = j + v[i][j] * dy[i];
			
			}
		}
	}
	
	cout << dp[n-1][n-1];
	
	return 0;
}
