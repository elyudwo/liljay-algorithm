#include <iostream>

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
    int answer = 2000000000;
    
    for(int i=1; i<=3; i++) {
        int dp[1002][4];
        
        for(int j=1; j<=3; j++) {
            dp[1][j] = arr[1][i];
        }
        
        for(int j=2; j<=n-1; j++) {
            for(int k=1; k<=3; k++) {
                if(j == 2 && k == i) { dp[j][k] = 20000; continue; }
                if (k == 1) {
                    dp[j][k] = min(dp[j-1][k+1], dp[j-1][k+2]);
                }
                if (k == 2) {
                    dp[j][k] = min(dp[j-1][k-1], dp[j-1][k+1]);
                }
                if (k == 3) {
                    dp[j][k] = min(dp[j-1][k-1], dp[j-1][k-2]);
                }
                dp[j][k] += arr[j][k];
            }
        }
        
        for(int j=1; j<=3; j++) {
            if(j == i) { continue; }
            if (j == 1) {
                dp[n][j] = min(dp[n-1][j+1], dp[n-1][j+2]);
            }
            if (j == 2) {
                dp[n][j] = min(dp[n-1][j-1], dp[n-1][j+1]);
            }
            if (j == 3) {
                dp[n][j] = min(dp[n-1][j-1], dp[n-1][j-2]);
            }
            
            dp[n][j] += arr[n][j];
            answer = min(answer, dp[n][j]);
        }
        
        // cout << endl;
        // for(int i=1; i<=n; i++) {
        //     for(int j=1; j<=3; j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        
    }
    
    cout << answer;
}

int main()
{
    input();
    solve();

    return 0;
}