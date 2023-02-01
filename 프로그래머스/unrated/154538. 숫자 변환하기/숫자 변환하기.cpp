#include <string>
#include <vector>
#include <queue>

using namespace std;


int bfs(int x, int y, int n) {
    queue<pair<int,int>> q;
    q.push({x,0});
    bool check[1000001] = {false,};
    int answer = 999999999;
    check[x] = true;
    
    while(!q.empty()) {
        int x = q.front().first;
        int cnt = q.front().second;
        q.pop();
        
        if(x == y) {
            answer = min(answer,cnt);
            continue;
        }
        
        int nx = x + n;
        if(nx <= 1000000 && !check[nx]) {
            check[nx] = true;
            q.push({nx,cnt+1});
        }
        
        nx = x * 2;
        if(nx <= 1000000 && !check[nx]) {
            check[nx] = true;
            q.push({nx,cnt+1});
        }
        
        nx = x * 3;
        if(nx <= 1000000 && !check[nx]) {
            check[nx] = true;
            q.push({nx,cnt+1});
        }
    }
    
    if(answer == 999999999) {
        return -1;
    }
    
    return answer;
}

int solution(int x, int y, int n) {
    int answer = 0;
    answer = bfs(x,y,n);
    
    return answer;
}