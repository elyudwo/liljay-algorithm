#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> v;
		vector<int> graph[1001];
		int degree[1001] = {0,};
		int result[1001] = {0,};
		
		v.push_back(-1);
		for(int i=0; i<n; i++) {
			int tmp;
			cin >> tmp;
			v.push_back(tmp);
			result[i+1] = tmp;
		}
		
		for(int i=0; i<k; i++) {
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			degree[b]++;
		}
		
		int end;
		cin >> end;
		
		queue<int> q;
		
		
		// 초기 셋팅 
		for(int i=1; i<=n; i++) { if(!degree[i]) { q.push(i); } }
	
		while(!q.empty()) {
			int x = q.front();
			q.pop();
			if(x == end) {
				cout << result[x] << '\n';
				break;
			}
			
			for(int i=0; i<graph[x].size(); i++) {
				int nx = graph[x][i];
				result[nx] = max(result[nx], result[x] + v[nx]);
				degree[nx]--;
				if(!degree[nx]) { q.push(nx); }
			}
		}
	
	}
}