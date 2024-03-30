#include <string>
#include <vector>

using namespace std;

int dp[100002][2];

void init(int t) {
    if(t) {
        dp[0][0] = 3;
        dp[0][1] = 1;
        return;
    }
    dp[0][0] = 2;
    dp[0][1] = 1;
}

int solution(int n, vector<int> tops) {
    int answer = 0;
    init(tops[0]);
    
    for(int i=1; i<tops.size(); i++) {
        if(tops[i]) {
            dp[i][0] = (dp[i-1][1] * 2 + dp[i-1][0] * 3) % 10007;
            dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % 10007;
            continue;
        }
        
        dp[i][0] = (dp[i-1][1] + dp[i-1][0] * 2) % 10007;
        dp[i][1] = (dp[i-1][1] + dp[i-1][0]) % 10007;
    }
    
    answer += (dp[n-1][0] + dp[n-1][1]) % 10007;
    
    return answer;
}