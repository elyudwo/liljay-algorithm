#include <string>
#include <vector>
#define INF 2e9

using namespace std;

bool visit[5][5][2];
int maze[5][5];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int answer = INF;
int x,y;
int r_start_x, r_start_y, b_start_x, b_start_y; 

void copy(vector<vector<int>> m) {
    for(int i=0; i<x; i++) {
        for(int j=0; j<y; j++) {
            maze[i+1][j+1] = m[i][j];
            if(maze[i+1][j+1] == 1) {
                r_start_x = i+1;
                r_start_y = j+1;
            }
            if(maze[i+1][j+1] == 2) {
                b_start_x = i+1;
                b_start_y = j+1;
            }
        }
    }
}

void dfs(int rx, int ry, int bx, int by, int cnt) {
    if(maze[rx][ry] == 3 && maze[bx][by] == 4) {
        answer = min(answer, cnt);
        return;
    }
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<4; j++) {
            int rxx = rx + dx[i];
            int ryy = ry + dy[i];
            int bxx = bx + dx[j];
            int byy = by + dy[j];
            if(maze[rx][ry] == 3) { rxx = rx; ryy = ry; }
            if(maze[bx][by] == 4) { bxx = bx; byy = by; }
            
            if((visit[rxx][ryy][0] && maze[rxx][ryy] != 3) 
                || (visit[bxx][byy][1] && maze[bxx][byy] != 4) || 
              maze[rxx][ryy] == 5 || maze[bxx][byy] == 5) continue;
            if(rxx < 1 || rxx > x || ryy < 1 || ryy > y ||
               bxx < 1 || bxx > x || byy < 1 || byy > y) continue;
            if(rxx == bxx && ryy == byy) continue;
            if(rxx == bx && ryy == by && bxx == rx && byy == ry) continue;
            
            
            visit[rxx][ryy][0] = true;
            visit[bxx][byy][1] = true;
            
            
            dfs(rxx, ryy, bxx, byy, cnt + 1);
            
            visit[rxx][ryy][0] = false;
            visit[bxx][byy][1] = false;
        }
    }
    
}

int solution(vector<vector<int>> maze) {
    x = maze.size();
    y = maze[0].size();
    copy(maze);
    visit[r_start_x][r_start_y][0] = true;
    visit[b_start_x][b_start_y][1] = true;
    
    dfs(r_start_x, r_start_y, b_start_x, b_start_y, 0);
    
    if(answer == 2e9) {
        answer = 0;
    }
    return answer;
}