#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
1. 여행 다니는게 손해인 시점 구하기 [1000일 이후부터는 여행다니면 손해]
2. 손해인 시점만큼 dp 배열을 만든다
3. dp 배열 채우고 1번과 계산하면서 가장 큰 시점을 구한다. 
*/

long long dp[1002][1001];
bool check[1002][1001];
int arr[1001];
int n,m,c;
vector<pair<int,int> > rem;

void input() {
	cin >> n >> m >> c;
	
	for(int i=1; i<=n; i++) {
		cin >> arr[i];
	}
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		rem.push_back({a, b});
	}
}

void solve() {
	check[0][1] = true;
	
	for(int i=1; i<=1000; i++) {
		for(int j=0; j<rem.size(); j++) {
			int start = rem[j].first;
			int end = rem[j].second;
			
			if(check[i-1][start] && dp[i][end] < dp[i-1][start] + arr[end]) {
				dp[i][end] = dp[i-1][start] + arr[end];
				check[i][end] = true;
			}
		}
	}
	
	long long answer = 0;
	
	for(int i=1; i<=1000; i++) {
		answer = max(answer, dp[i][1] - c * i * i);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}