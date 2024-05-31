#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;

/*
1. 생성한 정점 구하기
2. 생성한 정점과 연결된 점들 다 끊기
3. 각 그래프 별 개수 구하기
*/

vector<int> vec_in[1000002];
vector<int> vec_out[1000002];
bool check[1000002];
int max_value = 0, donut = 0, line = 0, eight = 0, makePoint;

void makeGraph(vector<vector<int>> edges) {
    for(vector<int> edge : edges) {
        int a = edge[0];
        int b = edge[1];
        max_value = max({max_value, a, b});
        
        vec_out[a].push_back(b);
        vec_in[b].push_back(a);
    }
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;
    makeGraph(edges);
    int makePoint, donut = 0, line = 0, eight = 0;
    
    for(int i=1; i<=max_value; i++) {
        if(vec_out[i].size() == 0 && vec_in[i].size() >= 1) {
            line++;
            continue;
        }
        if(vec_in[i].size() >= 2 && vec_out[i].size() >= 2) {
            eight++;
            continue;
        }
        if(vec_in[i].size() == 0 && vec_out[i].size() >= 2) {
            makePoint = i;
        }
    }
    
    donut = vec_out[makePoint].size() - (eight + line);
    
    answer.push_back(makePoint);
    answer.push_back(donut);
    answer.push_back(line);
    answer.push_back(eight);
    
    return answer;
}