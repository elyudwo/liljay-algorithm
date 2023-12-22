#include <iostream>

using namespace std;

int dp[2023][2023];
int arr[2001];
int n;

void init() {
    for(int i=1; i<=n; i++) {
        dp[i][i] = 1;
    }
    
    for(int i=1; i<=n; i++) {
        if(arr[i] == arr[i+1]) {
            dp[i][i+1] = 1;
        }
    }
}

void input() {
    cin >> n;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
    }
}

void calculate() {
    for(int i=2; i<=n; i++) {
        for(int j=1; j<=n; j++) {
            int idx = j + i;
            
            if(arr[j] == arr[idx] && dp[j+1][idx-1]) {
                dp[j][idx] = 1;
            }
            else {
                dp[j][idx] = 0;
            }
        }
    }
}

void solve() {
    init();
    calculate();
    
    int m;
    cin >> m;
    while(m--) {
        int s,e;
        cin >> s >> e;
        
        cout << dp[s][e] << '\n';
    }
}

int main()
{
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    input();
    solve();
    

    return 0;
}