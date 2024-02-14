#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

int n,m;
int dp[101][101];
bool check[101];

void input() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		check[tmp] = true;
	}
}

int dfs(int day, int coupon) {
	
	if(day >= n + 1) { return 0; }
	
	int &price = dp[day][coupon];
	
	if(price != -1) { return price; }
	
	if(check[day]) {
		price = dfs(day + 1, coupon);
	}
	else {
		price = 2e9;
		price = min(price, dfs(day + 1, coupon) + 10000);
		price = min(price, dfs(day + 3, coupon + 1) + 25000);
		price = min(price, dfs(day + 5, coupon + 2) + 37000);
		
		if(coupon >= 3) {
			price = min(price, dfs(day + 1, coupon - 3));
		}
	}
	
	return price;
}

void solve() {
	memset(dp, -1, sizeof(dp));
	
	cout << dfs(1, 0);
}

int main() {
	input();
	solve();
}