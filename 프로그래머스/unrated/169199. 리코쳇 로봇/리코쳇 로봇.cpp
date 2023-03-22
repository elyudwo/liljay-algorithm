#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n,m;
int answer = -1;
bool check[101][101];

struct b {
    int x;
    int y;
    int cnt;
};

void bfs(int x_tmp, int y_tmp, vector<string> board) {
    queue<b> q;
    q.push({x_tmp,y_tmp,0});
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        
        check[x][y] = true;
        if(board[x][y] == 'G') {
            answer = cnt;
            break;
        }
        q.pop();
        
        for(int i=0; i<4; i++) {
            int x1 = x;
            int y1 = y;
            while(1) {
                int nx = x1 + dx[i];
                int ny = y1 + dy[i];
                if(nx < 0 || ny < 0 || nx >=n || ny >= m || board[nx][ny] == 'D') {
                    if(!check[x1][y1]) {
                        q.push({x1,y1,cnt+1}); 
                    }
                    break;
                }
                else {
                    x1 = nx;
                    y1 = ny;
                }
            }
        }
    }
    
}

int solution(vector<string> board) {
    n = board.size();
    m = board[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(board[i][j] == 'R') {
                bfs(i,j,board);
            }
        }
    }
    
    return answer;
}