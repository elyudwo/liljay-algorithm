#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<pair<int,int> > graph[200002];
bool visited[200002]; 
int can_go[200002];
vector<int> rem;
bool check[200002];

int leaf;
int now = 0;
vector<int> idx_vec[2];
vector<int> rem_vec[2];

void input() {
	cin >> n >> m;
	
	for(int i=1; i<=m; i++) {
		int a,b;
		cin >> a >> b;
		graph[a].push_back({b, i});
		graph[b].push_back({a, i});

	}
}

int bfs(int idx) {
	int result = 0;
	queue<int> q;
	q.push(idx);
	check[idx] = true;
	
	while(!q.empty()) {
		int x = q.front();
		result++;
		q.pop();
		
		for(pair<int,int> p : graph[x]) {
			if(check[p.first]) { continue; }
			check[p.first] = true;
			q.push(p.first);
		}
	}
	
	return result;
}

int failCheck() {
	if(n == 2) { return 0; }
	
	int cnt = 0;
	int now = 0;
	
	for(int i=1; i<=n; i++) {
		if(!check[i]) {
			int tmp = bfs(i);
			if(tmp == now) {
			    return 0;
			}
			now = tmp;
			// 그래프의 노드가 두개일 경우 다른 크기로 분할 불가 
			
			cnt++;
		}
	}
	
	if(cnt == 1 && now <= 2) {
	    return 0;
	}
	
	if(cnt > 2) {
		return 0;
	}
	
	if(cnt == 2) {
		return 2;
	}
	
	return 1;
}

void dfs(int idx) {
    idx_vec[now].push_back(idx);
    leaf = idx;
	for(pair<int,int> p : graph[idx]) {
		// 방문했던거면 안감 
		if(visited[p.first] || can_go[p.second]) { 
			continue;
		}
		if(visited[p.first]) {
		    continue;
		}
		visited[p.first] = true;
		rem_vec[now].push_back(p.second);
		can_go[p.second] = true;
		dfs(p.first);
	}
	return;
}

void init() {
    for(int i=1; i<=200000; i++) {
        visited[i] = false;
        can_go[i] = false;
    }
}

void dfs2(int idx) {
	cout << idx << " ";
	for(pair<int,int> p : graph[idx]) {
		// 방문했던거 or leaf 포함하는거면 안감 
		if(visited[p.first] || can_go[p.second] || p.first == leaf) { 
			continue;
		}
	 	visited[p.first] = true;
		rem.push_back(p.second);
		can_go[p.second] = true;
		dfs2(p.first);
	}
}

void solve() {
	int cnt = failCheck();
	
	if(!cnt) {
		cout << "-1";
		return;
	}
	
	if(cnt == 2) {
		// 그래프 두개의 간선만 제거 
		for(int i=1; i<=n; i++) {
			if(!visited[i]) {
				visited[i] = true;
				dfs(i);
				
				for(int j=1; j<=m; j++) {
					can_go[j] = false;
				}
				now++;
			}
		}
		cout << idx_vec[0].size() << " " << idx_vec[1].size() << '\n';
		
		for(int i : idx_vec[0]) {
		    cout << i << " ";
		}
		cout << '\n';
		
		for(int i : rem_vec[0]) {
		    cout << i << " ";
		}
		cout << '\n';
		
		for(int i : idx_vec[1]) {
		    cout << i << " ";
		}
		cout << '\n';
		
		for(int i : rem_vec[1]) {
		    cout << i << " ";
		}
		cout << '\n';
		
		
		return;
	}
	
	// 그래프 리프노드 찾기
	dfs(1);
	init();
	
	
	cout << "1 " << n-1 << '\n';
	cout << leaf << '\n';
	
	
	int find;
	
	for(int i=1; i<=n; i++) {
	    if(i != leaf) {
	        find = i;
	        break;
	    }
	}
	visited[find] = true;
	dfs2(find);
	cout << '\n';
	for(int i : rem) {
		cout << i << " ";
	}
	
}

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	input();
	solve();
	
}