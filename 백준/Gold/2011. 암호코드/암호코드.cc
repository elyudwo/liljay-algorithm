#include <iostream>

using namespace std;

string str;
int arr[5001];
int dp[5001];
int answer = 0;

void input() {
	cin >> str;
	for(int i=1; i<=str.size(); i++) {
		arr[i] = str[i-1] - '0';
	}
}

bool checkFinish(int i, int tmp) {
	if(arr[i] == 0 && (tmp > 26 || tmp == 0)) {
		return true;
	}
	return false;
}

void solve() {
	dp[0] = 1;
	dp[1] = 1;
	
	if(arr[1] == 0) {
		cout << "0";
		return;
	}
	
	for(int i=2; i<=str.size(); i++) {
		int tmp = arr[i-1] * 10 + arr[i];
		
		if(checkFinish(i, tmp)) {
			cout << "0";
			return;
		}
		
		if(tmp > 26) {
			dp[i] = dp[i-1] % 1000000;
		}
		else if(arr[i] == 0 ) {
			dp[i] = dp[i-2] % 1000000;
		}
		else if(arr[i-1] == 0) {
			dp[i] = dp[i-1] % 1000000;
		}
		else if(tmp > 0 && tmp <= 26) {
			dp[i] = dp[i-1] % 1000000 + dp[i-2] % 1000000;
		}
	}
	
//	for(int i=0; i<=str.size(); i++) {
//		cout << dp[i] << " ";
//	}
	
	cout << dp[str.size()] % 1000000;
}

int main() {
	input();
	solve();
}