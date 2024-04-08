#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int check[102][102];
bool check_tmp[102][102];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void init(vector<vector<int>> rectangle) {
    for(vector<int> vec : rectangle) {
        int x1 = vec[0] * 2, y1 = vec[1] * 2, x2 = vec[2] * 2, y2 = vec[3] * 2;
        for(int i=x1; i<=x2; i++) {
            if(check[i][y1] != 2) {check[i][y1] = true;}
            if(check[i][y2] != 2) {check[i][y2] = true;}
        }
        
        for(int i=y1; i<=y2; i++) {
            if(check[x1][i] != 2) {check[x1][i] = true;}
            if(check[x2][i] != 2) {check[x2][i] = true;}
            
        }
        
        for(int i=x1+1; i<=x2-1; i++) {
            for(int j=y1+1; j<=y2-1; j++) {
                check[i][j] = 2;
            }
        }
    }
}

struct st {
    int x;
    int y;
    int cnt;
};

int bfs(int c_x, int c_y, int i_x, int i_y) {
    queue<st> q;
    q.push({c_x, c_y, 0});
    check_tmp[c_x][c_y] = true;
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cnt = q.front().cnt;
        
        if(x == i_x && y == i_y) {
            return cnt / 2 + cnt % 2; 
        }
        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            if(nx < 1 || ny < 1 || nx > 100 || ny > 100 || check_tmp[nx][ny] || check[nx][ny] != 1) continue;
            check_tmp[nx][ny] = true;
            q.push({nx, ny, cnt + 1});
        }
    }
}

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    init(rectangle);
    answer = bfs(characterX * 2, characterY * 2, itemX * 2, itemY * 2);
    
    return answer;
}