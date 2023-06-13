#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[201];
int dp[201];
int max_value = 0;
vector<int> vec;

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		int tmp;
		cin >> tmp;
		vec.push_back(tmp);
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		dp[i] = 1;
		for(int j=0; j<i; j++) {
			if(dp[i] < dp[j] + 1 && vec[i] > vec[j]) {
				dp[i] = dp[j] + 1;
			}
		}
		
		max_value = max(max_value, dp[i]);
	}
	
	cout << n - max_value;
}

int main() {
	input();
	solve();
	
}