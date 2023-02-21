#include <string>
#include <vector>
#include <queue>

using namespace std;

int answer = 999999999;
bool leverTrue[101][101];
bool leverFalse[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n,m;

struct go {
    int x;
    int y;
    bool lever;
    int time;
};

void bfs(vector<string> maps, int start_x, int start_y) {
    queue<go> q;
    q.push({start_x,start_y,false,0});
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        bool lever = q.front().lever;
        int time = q.front().time;
        q.pop();
        
        if(maps[x][y] == 'E' && lever) {
            answer = min(answer,time);
            continue;
        }
        
        for(int i=0; i<4; i++) {
            int nx = dx[i] + x;
            int ny = dy[i] + y;
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || maps[nx][ny] == 'X') { continue; }
            if(lever && leverTrue[nx][ny]) { continue; }
            if(!lever && leverFalse[nx][ny]) { continue; }
            
            if(lever) {
                q.push({nx,ny,true,time+1});
                leverTrue[nx][ny] = true;
            }
            else {
                if(maps[nx][ny] == 'L') {
                    q.push({nx,ny,true,time+1});
                    leverTrue[nx][ny] = true;
                }
                else {
                    q.push({nx,ny,false,time+1});
                    leverFalse[nx][ny] = true;
                }
            }
        }
    }
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            if(maps[i][j] == 'S') {
                bfs(maps,i,j);
            }
        }
    }
    if(answer == 999999999) {
        answer = -1;
    }
    
    return answer;
}