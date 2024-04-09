#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

/*
1. 간선들 다 더해서 0이 아니면 -1 return
2. 0일 경우 

*/
vector<int> graph[300001];
long long sum[300001];
long long answer = 0;

void makeGraph(vector<vector<int>> edges) {
    for(vector<int> vec : edges) {
        graph[vec[0]].push_back(vec[1]);
        graph[vec[1]].push_back(vec[0]);
    }
}

void dfs(int me, int parent) {
    
    for(int idx : graph[me]) {
        if(idx == parent) { continue; }
        dfs(idx, me);
    }
    
    sum[parent] += sum[me];
    answer += abs(sum[me]);
    
}

long long solution(vector<int> a, vector<vector<int>> edges) {
    makeGraph(edges);
    for(int i=0; i<a.size(); i++) { sum[i] = a[i]; }
    
    dfs(0, 0);
    
    if(sum[0] != 0) { return -1; }
    return answer;
}