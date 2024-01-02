#include <iostream>
#define MAX 2000000000
using namespace std;

int n;
int arr[1002][5];

void input() {
    cin >> n;
    
    for(int i=1; i<=n; i++) {
        arr[i][0] = 1001;
        for(int j=1; j<=3; j++) {
            cin >> arr[i][j];
        }
        arr[i][4] = 1001;
    }
}

void solve() {
    int answer = MAX;
    
    for(int i=1; i<=3; i++) {
        int dp[1002][4];
        
        for(int j=1; j<=3; j++) {
            if(i == j) {
                dp[1][j] = arr[1][j];
                continue;
            }
            dp[1][j] = MAX;
        }
        
        for(int j=2; j<=n; j++) {
            dp[j][1] = min(dp[j-1][2], dp[j-1][3]) + arr[j][1];
            dp[j][2] = min(dp[j-1][1], dp[j-1][3]) + arr[j][2];
            dp[j][3] = min(dp[j-1][1], dp[j-1][2]) + arr[j][3];
        }
        
        for(int j=1; j<=3; j++) {
            if(j == i) { continue; }
            answer = min(answer, dp[n][j]);
        }
    }
    
    cout << answer;
}

int main()
{
    input();
    solve();

    return 0;
}