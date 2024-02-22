#include <iostream>
#include <algorithm>

using namespace std;

string str1, str2, str3;
int dp[102][102][102];

void input() {
	cin >> str1 >> str2 >> str3;
	str1 = " " + str1;
	str2 = " " + str2;
	str3 = " " + str3;
}

void solve() {
	for(int i=1; i<=str1.size(); i++) {
		for(int j=1; j<=str2.size(); j++) {
			for(int k=1; k<=str3.size(); k++) {
				if(str1[i] == str2[j] && str2[j] == str3[k]) {
					dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
				}
				else {
					dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
				}
			}
		}
	}
	
	cout << dp[str1.size() - 1][str2.size() - 1][str3.size() - 1];
}

int main() {
	input();
	solve();
	
}