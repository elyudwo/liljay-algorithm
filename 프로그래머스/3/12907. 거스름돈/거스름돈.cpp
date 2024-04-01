#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[100002];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    dp[0] = 1;
    for(int i=0; i<money.size(); i++) {
        int num = money[i];
        for(int j=num; j<=100000; j++) {
            dp[j] = (dp[j] + dp[j - num]) % 1000000007;
        }
    }
    
    answer = dp[n];
    
    return answer;
}