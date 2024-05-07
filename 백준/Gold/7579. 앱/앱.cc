#include <iostream>
#define INF 1e9
using namespace std;

typedef long long ll;

int n, m, sum = 0;
int mem[102];
int price[102];
ll dp[102][10002];
int answer = INF;

void input() {
	cin >> n >> m;
	int tmp;
	
	for(int i=1; i<=n; i++) {
		cin >> tmp;
		mem[i] = tmp;		
	}
	
	for(int i=1; i<=n; i++) {
		cin >> tmp;
		price[i] = tmp;
		sum += tmp;
	}
}

void solve() {
	for(int i=1; i<=n; i++) {
		for(int j=0; j<=sum; j++) {
			if(price[i] > j) {
				dp[i][j] = dp[i-1][j];
				continue;
			}
			
			dp[i][j] = max(dp[i-1][j], dp[i-1][j - price[i]] + mem[i]);
			if(dp[i][j] >= m) {
				answer = min(answer, j);
			}
		}
	}
	
	
	cout << answer;
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	input();
	solve();
	
}