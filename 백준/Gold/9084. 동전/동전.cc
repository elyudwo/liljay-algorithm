#include <iostream>

using namespace std;

int arr[11] = {0,};
int dp[21][10001];

void init() {
	for(int i=0; i<11; i++) {
		arr[i] = 0;
	}
	for(int i=0; i<21; i++) {
		for(int j=0; j<10001; j++) {
			dp[i][j] = 0;
		}
	}
}
        
int main()
{
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        int answer = 0;
        
        cin >> n;
        
        for(int i=1; i<=n; i++) { 
            cin >> arr[i]; 
            dp[i][arr[i]] = 1; 
        }
        
        cin >> m;
        
        for(int i=1; i<=m; i++) {
            for(int j=1; j<=n; j++ ) {
                for(int k=j; k>=1; k--) {
                    dp[j][i] += dp[k][i - arr[j]];
                }
            }
        }
        
    
        
        for(int i=1; i<=n; i++) {
            answer += dp[i][m];
        }
        
        cout << answer << '\n';
        
        init(); 
    }
    
    return 0;
}