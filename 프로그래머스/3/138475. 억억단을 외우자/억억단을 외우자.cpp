#include <string>
#include <vector>
#include <iostream>

using namespace std;


/*
1. 1 ~ 5,000,000 배열에 약수 개수(?) 구하기
2. e~s 사이에서 가장 큰 것 구하기 (시간 복잡도 초과)
*/

int arr[5000002];
int dp[5000002];

vector<int> solution(int e, vector<int> starts) {
    vector<int> answer;

    for(int i=1; i<=e; i++) {
        for(int j=1; j<=e/i; j++) { 
            arr[j * i]++; 
        } 
    }
    
    int tmp = arr[e];
    int idx = e;
    dp[e] = e;
    
    for(int i=e-1; i>=1; i--) {
        if(tmp <= arr[i]) {
            tmp = arr[i];
            idx = i;
            dp[i] = i;
            continue;
        }
        dp[i] = idx;
    }
    
    // for(int i=1; i<=e; i++) {
    //     cout << dp[i] << " ";
    // }
    
    for(int i : starts) {
        answer.push_back(dp[i]);
    }
    
    return answer;
}