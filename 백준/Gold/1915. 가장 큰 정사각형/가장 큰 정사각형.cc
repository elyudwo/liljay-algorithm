#include <iostream>
#include <algorithm>

using namespace std;

int n,m;
int arr[1002][1002];
int dp[1002][1002];
bool check = false;

void input() {
    cin >> n >> m;
	for(int i=1; i<=n; i++) {
	    string str;
	    cin >> str;
		for(int j=1; j<=m; j++) {
			arr[i][j] = str[j-1] - '0';
			if(arr[i][j] == 1) { dp[i][j] = 1; check = true; }
		}
	}
}

void print() {
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

void solve() {
	int answer = 0;
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=m; j++) {
		    if(arr[i][j] == 0) { continue; }
		    
			int tmp = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
			if(!dp[i][j-1] || !dp[i-1][j] || !dp[i-1][j-1]) { continue; }
			
			
			dp[i][j] = max(dp[i][j], tmp + 1);
			answer = max(answer, dp[i][j] * dp[i][j]);
		}
	}
	
// 	print();
    if(answer == 0 && check) {
        answer = 1;
    }
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}