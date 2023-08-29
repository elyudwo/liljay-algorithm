#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define INF 2000000000;
using namespace std;


int arr[26][26];
bool check[5][26][26];
int rem[4][26][26];
int answer = INF;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int n;

struct car {
    int x;
    int y;
    int cost;
    int dist;
};

void bfs() {
    queue<car> q;
    q.push({0,0,0,-1});
    
    while(!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        int cost = q.front().cost;
        int dist = q.front().dist;
        
        q.pop();
        
        if(x == n-1 && y == n-1) {
            answer = min(answer, cost);
            continue;
        }
        
        for(int i=0; i<4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= n || ny >= n || arr[nx][ny] == 1) continue;
            
            if(dist == -1) { q.push({nx, ny, cost + 100, i}); rem[i][nx][ny] = 100; }
            else if(dist != i) {
                if(cost + 600 <= rem[i][nx][ny]) {
                    q.push({nx, ny, cost + 600, i});
                    rem[i][nx][ny] = cost + 600;
                }
            }
            else if(dist == i) {
                if(cost + 100 <= rem[i][nx][ny]) {
                    q.push({nx, ny, cost + 100, i}); 
                    rem[i][nx][ny] = cost + 100;
                }
            }
        }
    }
}

int solution(vector<vector<int>> board) {
    n = board.size();
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            arr[i][j] = board[i][j];
        }
    }
    
    for(int i=0; i<4; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                rem[i][j][k] = INF;
            }
        }
    }
    
    bfs();
    
    return answer;
}