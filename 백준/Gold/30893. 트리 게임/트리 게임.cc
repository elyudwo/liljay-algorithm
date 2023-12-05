#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,s,e;
vector<int> vec[100001];
bool check[100001] = {false,};
bool checkDfs[100001] = {false,};
int dist;
string answer = "Second";

void input() {
	cin >> n >> s >> e;
	
	for(int i=0; i<n-1; i++) {
		int a,b;
		cin >> a >> b;
		vec[a].push_back(b);
		vec[b].push_back(a);
	}
}



void bfs() {
	queue<pair<int,int> > q;
	q.push({s,0});
	
	while(!q.empty()) {
		int x = q.front().first;
		int time = q.front().second;
		q.pop();
		
		if(x == e) {
			dist = time;
			return;
		}
		
		for(int i=0; i<vec[x].size(); i++) {
		    if(check[vec[x][i]]) continue;
			check[vec[x][i]] = true;
			q.push({vec[x][i], time + 1});
		}
	}
}

void dfs(int x, int time) {
    if(x == s) {  answer = "First"; return; }
    if(checkDfs[x]) return;
    checkDfs[x] = true;
    
    if(dist % 2 == 1) {
        if(time % 2 == 0) {
            if(vec[x].size() > 2) {
                return;
            }
            else {
                for(int i=0; i<vec[x].size(); i++) {
                    if(!checkDfs[vec[x][i]]) {
                        dfs(vec[x][i], time + 1);
                    }
                }
            }
        }
        else {
            for(int i=0; i<vec[x].size(); i++) {
                dfs(vec[x][i], time + 1);
            }
        }
    }
    else {
        if(time % 2 == 1) {
            if(vec[x].size() > 2) {
                return;
            }
            else {
                for(int i=0; i<vec[x].size(); i++) {
                    if(!checkDfs[vec[x][i]]) {
                        dfs(vec[x][i], time + 1);
                    }
                }
            }
        }
        else {
            for(int i=0; i<vec[x].size(); i++) {
                dfs(vec[x][i], time + 1);
            }
        }
    }
}

void solve() {
	bfs();
	for(int i=0; i<vec[e].size(); i++) {
	    dfs(vec[e][i], 1);
	}
	
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}