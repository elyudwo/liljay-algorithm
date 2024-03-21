#include <vector>
#include <iostream>

using namespace std;

int MOD = 20170805;
// 0 == 옆, 1 == 위
long long dp[502][502][2];
long long arr[502][502];

void init() {
    for(int i=0; i<=501; i++) {
        for(int j=0; j<=501; j++) {
            dp[i][j][0] = 0;
            dp[i][j][1] = 0;
            arr[i][j] = 0;
        }
    }
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    int answer = 0;
    init();
    // 숨 쉴 공간
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            arr[i][j] = city_map[i-1][j-1];
        }
    }
    
    dp[1][1][0] = 1;
    
    // 1 == 오른쪽, 0 == 아래
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            if(arr[i][j] == 1) continue;
            if(arr[i][j] == 0) {
                dp[i+1][j][1] += (dp[i][j][0] + dp[i][j][1]) % 20170805;
                dp[i][j+1][0] += (dp[i][j][0] + dp[i][j][1]) % 20170805;
            }
            if(arr[i][j] == 2) {
                dp[i+1][j][1] += (dp[i][j][1]) % 20170805;
                dp[i][j+1][0] += (dp[i][j][0]) % 20170805;
            }
        }
    }
    
    
    // for(int i=1; i<=m; i++) {
    //     for(int j=1; j<=n; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    answer = (dp[m][n][0] + dp[m][n][1]) % 20170805;
    return answer;
}