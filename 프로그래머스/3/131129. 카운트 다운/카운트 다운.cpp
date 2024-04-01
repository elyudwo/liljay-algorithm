#include <string>
#include <vector>
#include <set>
#define INF 1e9
using namespace std;

long long dp[100002];
int dp_sum[100002];

set<int> se;
bool check[61];

void init() {
    for(int i=0; i<=100000; i++) {
        dp[i] = INF;
    }
    
    for(int i=1; i<=20; i++) {
        for(int j=1; j<=3; j++) {
            se.insert(i * j);
            dp[i * j] = 1;
            if(j == 1) {
                check[i * j] = true;
                dp_sum[i * j] = 1;
            }
        }
    }
    check[50] = true;
    dp[50] = 1;
    dp_sum[50] = 1;
    se.insert(50);
}

vector<int> solution(int target) {
    vector<int> answer;
    init();
    
    int dart = 0, sum = 0;
    
    for(int i=1; i<=100000; i++) {
        for(int s : se) {
            int tmp = i - s;
            if(tmp <= 0) { continue; }
            
            if(dp[i] == dp[tmp] + 1 && dp_sum[i] <= dp_sum[tmp]) {
                if(check[s]) {
                    dp_sum[i] = dp_sum[tmp] + 1;
                    continue;
                }
                dp_sum[i] = dp_sum[tmp];
            }
            else if(dp[i] > dp[tmp] + 1) {  
                dp[i] = dp[tmp] + 1;
                if(check[s]) {
                    dp_sum[i] = dp_sum[tmp] + 1;
                    continue;
                }
                dp_sum[i] = dp_sum[tmp];
            }
        }
    }
    
    answer.push_back(dp[target]);
    answer.push_back(dp_sum[target]);
    
    return answer;
}