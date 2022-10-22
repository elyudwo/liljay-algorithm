#include <iostream>

using namespace std;

int v[1025][1025];
int dp[1025][1025];


int main(void)
{
	int n,m;
	cin >> n >> m;
	
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=n; j++) {
			scanf("%d",&v[i][j]);
		}
	}
	
	
	for(int i=1; i<=n; i++) {
		dp[i][1] = v[i][1];
		for(int j=2; j<=n; j++) {
			dp[i][j] = dp[i][j-1] + v[i][j];
		}
	}
	
	
	
	for(int i=0; i<m; i++) {
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int sum = 0;
		for(int i=x2; i>=x1; i--) {
			sum = sum + (dp[i][y2] - dp[i][y1-1]);
		}
		printf("%d\n",sum);
	}
	
	
	return 0;
}
