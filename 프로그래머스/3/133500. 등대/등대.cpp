#include <string>
#include <vector>

using namespace std;

vector<int> graph[100001];
bool light[100001];
int answer = 0;

void init(vector<vector<int>> lighthouse) {
    for(vector<int> vec : lighthouse) {
        int a = vec[0];
        int b = vec[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
}

void dfs(int node, int parent) {
    for(int i=0; i<graph[node].size(); i++) {
        int x = graph[node][i];
        if(x != parent) {
            dfs(x, node);
            if(!light[x] && !light[node]) {
                light[node] = true;
                answer++;
            }
        }
    }
}

int solution(int n, vector<vector<int>> lighthouse) {
    init(lighthouse);
    dfs(1, 1);
    
    return answer;
}