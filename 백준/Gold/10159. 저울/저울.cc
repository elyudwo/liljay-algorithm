#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> big[101];
vector<int> small[101];
bool check_big[101];
bool check_small[101];
int n,m;

void input() {
	cin >> n;
	cin >> m;
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		big[b].push_back(a);
		small[a].push_back(b);
	}
}

void bfs_big(int idx) {
	queue<int> q;
	q.push(idx);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(int i=0; i<big[x].size(); i++) {
			int nx = big[x][i];
			if(!check_big[nx]) {
				check_big[nx] = true;
				q.push(nx);
			}
		}
	}
}

void bfs_small(int idx) {
	queue<int> q;
	q.push(idx);
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(int i=0; i<small[x].size(); i++) {
			int nx = small[x][i];
			if(!check_small[nx]) {
				check_small[nx] = true;
				q.push(nx);
			}
		}
	}
}

int checkCant() {
	int result = 0;
	for(int i=1; i<=n; i++) {
		if(check_big[i] || check_small[i]) { result += 1; }
		check_big[i] = false;
		check_small[i] = false;
	}
	
	return result;
}

void solve() {
	for(int i=1; i<=n; i++) {
		bfs_big(i);
		bfs_small(i);
		check_big[i] = true;
		cout << n - checkCant() << '\n';
	}
}

int main() {
	input();
	solve(); 
	
	
}