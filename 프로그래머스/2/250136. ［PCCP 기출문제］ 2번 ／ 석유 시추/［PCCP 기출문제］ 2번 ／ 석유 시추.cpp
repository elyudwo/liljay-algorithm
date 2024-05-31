#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <iostream>
#include <unordered_set>

using namespace std;

/*
1. 각 땅마다 번호를 매김
2. 시추선 투입
3. 번호 중복되지 않게 더해감
*/

bool check[501][501];
int oil_num[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int oil[250001];
int idx = 1;
int row, column;
int land_arr[502][502];

void bfs(int x, int y) {
    int cnt = 0;
    queue<pair<int,int>> q;
    q.push({x, y});
    
    while(!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        oil_num[x][y] = idx;
        cnt++;
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(check[nx][ny] || nx < 0 || ny < 0 || nx >= row || ny >= column || !land_arr[nx][ny]) continue;
            check[nx][ny] = true;
            q.push({nx, ny});
        }
    }
    
    oil[idx] = cnt;
    idx++;
}

int solution(vector<vector<int>> land) {
    int answer = 0;
    row = land.size();
    column = land[0].size();
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            land_arr[i][j] = land[i][j];
        }
    }
    
    for(int i=0; i<row; i++) {
        for(int j=0; j<column; j++) {
            if(!check[i][j] && land[i][j]) {
                check[i][j] = true;
                bfs(i, j);
            }
        }
    }
    
    for(int i=0; i<column; i++) {
        unordered_set<int> se;
        int result = 0;
        
        for(int j=0; j<row; j++) {
            if(oil_num[j][i] != 0 && !se.count(oil_num[j][i])) {
                se.insert(oil_num[j][i]);
                result += oil[oil_num[j][i]];
            }
        }
        answer = max(answer, result);
    }
    
    return answer;
}