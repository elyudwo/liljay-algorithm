#include <string>
#include <vector>
#define INF 2000000000

using namespace std;

int dp[100001][10][10];
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
    for(int i=0; i<=100000; i++) {
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                dp[i][j][k] = INF;
            }
        }
    }
    dp[0][4][6] = 0;
}

int solution(string numbers) {
    int answer = INF;
    init();
    
    for(int i=0; i<numbers.size(); i++) {
        int num = numbers[i] - '0';
        
        for(int j=0; j<10; j++) {
            for(int k=0; k<10; k++) {
                if(dp[i][j][k] != INF) {
                    if(k != num) {
                        dp[i+1][num][k] = min(dp[i+1][num][k], dp[i][j][k] + dist[j][num]);
                    }
                    if(j != num) {
                        dp[i+1][j][num] = min(dp[i+1][j][num], dp[i][j][k] + dist[k][num]);
                    }
                }
            }
        }
    }
    
    int s = numbers.size();
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            answer = min(answer, dp[s][i][j]);
        }
    }
    
    return answer;
}