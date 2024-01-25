#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> graph[1000002];
int in[1000002];
int out[1000002];
bool check[1000002];
int donut = 0, line = 0, eight = 0;

void makeGraph(vector<vector<int>> edges) {
    for(vector<int> edge : edges) {
        int a = edge[0];
        int b = edge[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
        out[a] += 1;
        in[b] += 1;
    }
}

int checkMakePoint() {
    int makePoint;
    for(int i=1; i<=1000000; i++) {
        if(!in[i] && out[i] >= 2) {
            makePoint = i;
            check[i] = true;
            break;
        }
    }
    
    for(int i=0; i<graph[makePoint].size(); i++) {
        in[graph[makePoint][i]] -= 1;
    }
    
    return makePoint;
}


void bfs(int x) {
    queue<int> q;
    q.push(x);
    check[x] = true;
    bool lineB = false, eightB = false, donutB = false;
    
    
    while(!q.empty()) {
        int nx = q.front();
        if(in[nx] && !out[nx]) { lineB = true; }
        if(in[nx] == 2 && out[nx] == 2) { eightB = true; }
        
        q.pop();
        
        for(int i=0; i<graph[nx].size(); i++) {
            int tmp = graph[nx][i];
            if(check[tmp]) { continue; }
            check[tmp] = true;
            q.push(tmp);
        }
    }
    if(lineB) { line++; }
    if(eightB) { eight++; }
    if(!lineB && !eightB) { donut++; }
    
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    makeGraph(edges);
    
    answer.push_back(checkMakePoint());
    
    for(int i=0; i<edges.size(); i++) {
        if(!check[edges[i][0]]) { bfs(edges[i][0]); }
    }
    
    for(int i=0; i<edges.size(); i++) {
        if(!check[edges[i][0]]) {
            line++;
            check[edges[i][0]] = true;
        }
        if(!check[edges[i][1]]) {
            check[edges[i][1]] = true;
            line++;
        }
    }
    
    answer.push_back(donut);
    answer.push_back(line);
    answer.push_back(eight);
    
    return answer;
}