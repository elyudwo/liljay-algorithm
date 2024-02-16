#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long arr[1002][1002];
long long sum[1002][1002];
int n,m;

void calculateSum() {
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            arr[i][j] = arr[i][j] + arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            sum[i][j] += arr[i][j];
        }
    }
    
    
    // for(int i=1; i<=n; i++) {
    //     for(int j=1; j<=m; j++) {
    //         cout << sum[i][j] << " ";
    //     }
    //     cout << endl;
    // }
}

int calculateNotDestroyed() {
    int notDestroyed = 0;
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            if(sum[i][j] > 0) {
                notDestroyed++;
            }
        }
    }
    
    return notDestroyed;
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    n = board.size();
    m = board[0].size();
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=m; j++) {
            sum[i][j] = board[i-1][j-1];
        }
    }
    
    for(vector<int> vec : skill) {
        int x1 = vec[1] + 1, y1 = vec[2] + 1, x2 = vec[3] + 1, y2 = vec[4] + 1, cnt = vec[5];
        
        if(vec[0] == 2) {
            arr[x1][y1] += cnt;
            arr[x2+1][y2+1] += cnt;
            arr[x2+1][y1] -= cnt;
            arr[x1][y2+1] -= cnt;
            continue;
        }
        arr[x1][y1] -= cnt;
        arr[x2+1][y2+1] -= cnt;
        arr[x2+1][y1] += cnt;
        arr[x1][y2+1] += cnt;
    }
    
    calculateSum();
    answer = calculateNotDestroyed();
    
    return answer;
}