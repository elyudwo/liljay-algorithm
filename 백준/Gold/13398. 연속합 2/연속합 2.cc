#include <iostream>

using namespace std;

int n;
int arr[100001];
int dp[2][100001];
int answer = -1001;

void input() {
    cin >> n;
    dp[0][0] = -1001;
    dp[0][1] = -1001;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    for(int i=1; i<=n; i++) {
        dp[0][i] = max(dp[0][i-1] + arr[i], arr[i]);
        answer = max(answer, dp[0][i]);
        
        dp[1][i] = max(dp[1][i-1] + arr[i], dp[0][i-1]);
        answer = max(answer, dp[1][i]);
    }
    
    cout << answer;
}

int main()
{
    input();
    solve();
    
    
    return 0;
}