#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#define INF 2e9
using namespace std;

long long dp[100002][10][10];
int dist[10][10]={
    { 1, 7, 6, 7, 5, 4, 5, 3, 2, 3 },
    { 7, 1, 2, 4, 2, 3, 5, 4, 5, 6 },
    { 6, 2, 1, 2, 3, 2, 3, 5, 4, 5 },
    { 7, 4, 2, 1, 5, 3, 2, 6, 5, 4 },
    { 5, 2, 3, 5, 1, 2, 4, 2, 3, 5 },
    { 4, 3, 2, 3, 2, 1, 2, 3, 2, 3 },
    { 5, 5, 3, 2, 4, 2, 1, 5, 3, 2 },
    { 3, 4, 5, 6, 2, 3, 5, 1, 2, 4 },
    { 2, 5, 4, 5, 3, 2, 3, 2, 1, 2 },
    { 3, 6, 5, 4, 5, 3, 2, 4, 2, 1 }
};

void init() {
    for(int i=0; i<=100001; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
}

int solution(string numbers) {
    long long answer = INF;
    init();
    dp[0][4][6] = 0;
    
    for(int i=0; i<numbers.size(); i++) {
        int num = numbers[i] - '0';
        
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                if(dp[i][j][k] != INF) {
                    if(num != k) {
                        dp[i+1][num][k] = min(dp[i+1][num][k], dp[i][j][k] + dist[j][num]);
                    }
                    if(num != j) {
                        dp[i+1][j][num] = min(dp[i+1][j][num], dp[i][j][k] + dist[k][num]);
                    }
                }
            }
        }
    }
    
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            answer = min(dp[numbers.size()][i][j], answer);
        }
    }
    
    return answer;
}