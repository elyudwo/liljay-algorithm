#include <iostream>
#include <vector>
#include <queue>
#define INF 2000000000

using namespace std;

int v,e,p;
vector<pair<int,int> > graph[5002];
int arr[5002];
int rem = INF;
bool result = false;

void input() {
    cin >> v >> e >> p;
	
    for(int i=0; i<e; i++) {
        int a,b,c;
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    
    for(int i=1; i<=5000; i++) {
        arr[i] = INF;
    }
}

struct go {
    int now;
    int cost;
    bool gunwoo;
};

void bfs() {
    queue<go> q;
    if(p == 1) {
    	q.push({1, 0, true});
	}
	else {
		q.push({1, 0, false});
	}
    
    while(!q.empty()) {
        int x = q.front().now;
        int cost = q.front().cost;
        bool gunwoo = q.front().gunwoo;
        q.pop();
        
        if(x == v) {
        	if(cost <= rem) {
        		if(cost == rem) {
        			if(!result && gunwoo) {
        				result = gunwoo;
					}
        			continue;
				}
        		result = gunwoo;	
        		rem = cost;
			}
            continue;
        }
        
        for(int i=0; i<graph[x].size(); i++) {
            int nx = graph[x][i].first;
            
            if(cost + graph[x][i].second <= arr[nx]) {
                arr[nx] = cost + graph[x][i].second;
				if(nx == p) {
                	q.push({nx, cost + graph[x][i].second, true});
                }
                else {
                	q.push({nx, cost + graph[x][i].second, gunwoo});
				}
            }
        }
    }
}

void solve() {
    bfs();
    if(result) {
        cout << "SAVE HIM";
        return;
    }
    cout << "GOOD BYE";
}

int main()
{
    input();
    solve();
    
    return 0;
}