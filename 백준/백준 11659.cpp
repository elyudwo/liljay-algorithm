#include <iostream>

using namespace std;

int v[100001];
int dp[100001];
int main(void)
{
	int n,m;
	scanf("%d %d",&n,&m);
	
	for(int i=1; i<=n; i++) {
		scanf("%d",&v[i]);
	}
	dp[0] = 0;
	dp[1] = v[1];
	
	for(int i=2; i<=n; i++) {
		dp[i] = v[i] + dp[i-1];
	}
	
	for(int i=0; i<m; i++) {
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",dp[b] - dp[a-1]);
	}
	
	return 0;
}
