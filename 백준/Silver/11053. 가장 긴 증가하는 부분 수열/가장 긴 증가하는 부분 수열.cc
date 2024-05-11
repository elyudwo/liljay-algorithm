#include <iostream>
#include <vector>

using namespace std;

int n;
int dp[1002];
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
	int answer = 1;
	for(int i=0; i<=n; i++) {
		dp[i] = 1;
	}
	
	for(int i=1; i<n; i++) {
		for(int j=i-1; j>=0; j--) {
			if(vec[i] > vec[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
				answer = max(answer, dp[i]);
			}
		}
	}	
	
	cout << answer;
}

int main() {
	input();
	solve();
		
}