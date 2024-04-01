#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

/*
1. 지는 놈 -> 이기는 놈 으로 간선 연결
*/

vector<int> graph[102];
vector<int> graph_win[102];
int lose_cnt[102];
int win_cnt[102];

void init(vector<vector<int>> results) {
    for(vector<int> vec : results) {
        int a = vec[0];
        int b = vec[1];
        
        graph[b].push_back(a);
        graph_win[a].push_back(b);
    }
    
    for(int i=0; i<=100; i++) {
        lose_cnt[i] = 0;
        win_cnt[i] = 0;
    }
}

int bfs(int x) {
    queue<int> q;
    bool check[101] = {false,};
    q.push(x);
    check[x] = true;
    int lose = 0;
    
    while(!q.empty()) {
        int x = q.front();
        lose++;
        q.pop();
        
        for(int i=0; i<graph[x].size(); i++) {
            int nx = graph[x][i];
            if(check[nx]) continue;
            check[nx] = true;
            q.push(nx);
        }
    }
    return lose - 1;
}

int bfs_win(int x) {
    queue<int> q;
    bool check[101] = {false,};
    q.push(x);
    check[x] = true;
    int lose = 0;
    
    while(!q.empty()) {
        int x = q.front();
        lose++;
        q.pop();
        
        for(int i=0; i<graph_win[x].size(); i++) {
            int nx = graph_win[x][i];
            if(check[nx]) continue;
            check[nx] = true;
            q.push(nx);
        }
    }
    return lose - 1;
}

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    init(results);
    
    for(int i=1; i<=n; i++) { 
        lose_cnt[i] = bfs(i);
        win_cnt[i] = bfs_win(i);
        // cout << i << " " << lose_cnt[i] <<  " " << win_cnt[i] << endl;
    }
    
    for(int i=n; i>=1; i--) {
        int num = i-1;
        
        for(int j=1; j<=n; j++) {
            if(lose_cnt[j] == num && win_cnt[j] == (n - 1) - num) {
                answer++;
            }
            
        }
    }
    
    
    return answer;
} 