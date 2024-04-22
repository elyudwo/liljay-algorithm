#include <iostream>
#include <algorithm>

using namespace std;

string str1, str2;
char c1[1002];
char c2[1002];
int dp[1002][1002];
int n,m;

void input() {
   cin >> str1;
   cin >> str2;
   
   if(str1.size() < str2.size()) {
       string tmp = str1;
       str1 = str2;
       str2 = tmp;
   }
   n = str1.size();
   m = str2.size();
}

void copy() {
   for(int i=0; i<n; i++) {
      c1[i+1] = str1[i];
      dp[i][0] = i;
   }
   dp[n][0] = n;
   
   for(int i=0; i<m; i++) {
      c2[i+1] = str2[i];
      dp[0][i] = i;
   }
   dp[0][m] = m;
}

void solve() {
   copy();
   
   for(int i=1; i<=n; i++) {
      for(int j=1; j<=m; j++) {
         if(c1[i] == c2[j]) {
            dp[i][j] = dp[i-1][j-1];
            continue;
         }
         dp[i][j] = min({dp[i-1][j] + 1, dp[i][j-1] + 1, dp[i-1][j-1] + 1});
      }
   }
  
    // cout << dp[2][1] << " " << dp[1][0] << " " << dp[2][0];
  
  cout << dp[n][m];
}

int main() {
   input();
   solve();
   
}