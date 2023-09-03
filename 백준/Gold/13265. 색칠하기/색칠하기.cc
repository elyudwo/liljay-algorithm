#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> vec[1001];
bool check[1001];
bool result = true;
int rem[1001];
int n,m;

void bfs(int num) {
	queue<int> q;
	q.push(num);
	check[num] = true;
	rem[num] = 1;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for(int i=0; i<vec[x].size(); i++) {
			int nx = vec[x][i];
			if(check[nx]) {
				if(rem[nx] == rem[x]) {
					cout << "impossible" << '\n';
					result = false;
					return;
				}
				continue;
			}
			check[nx] = true;
			
			if(rem[x] == 1) { rem[nx] = 2; }
			else if(rem[x] == 2) { rem[nx] = 1; }
			q.push(nx);
		}
	}
}

void print() {
	for(int i=1; i<=n; i++) {
		cout << rem[i] << " ";
	}
	cout << endl;
}
	
int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	
	while(t--) {
		cin >> n >> m;
		
		for(int i=0; i<m; i++) {
			int a,b;
			cin >> a >> b;
			vec[a].push_back(b);
			vec[b].push_back(a);
		}
		
		for(int i=1; i<=n; i++) {
			if(!check[i]) { bfs(i); }
			if(!result) break;
		}
		
		//print();
		
		if(result) { cout << "possible" << '\n'; }
		
		// init
		for(int i=1; i<=n; i++) {
			vec[i].clear();
			check[i] = false;
		}
		result = true;
	}
}