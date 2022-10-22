#include <iostream>
#include <algorithm>
using namespace std;

int v[1001][1001];

int dx[] = {1,0,1};
int dy[] = {0,1,1};
int dp[1001][1001];
int max_sum = -1;
int n,m;

int main(void)
{

	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			scanf("%d",&v[i][j]); 
		}
	}
	
	dp[1][1] = v[1][1];
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
			for(int q=0; q<3; q++) {
				int nx = i + dx[q];
				int ny = j + dy[q];
				
				dp[nx][ny] = max(dp[nx][ny],dp[i][j] + v[nx][ny]);
			}
		}
	}
	
	printf("%d",dp[n][m]);
	
	return 0;
}
