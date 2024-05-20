#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
vector<int> vec[51];
int answer = 0;

void bfs(int x) {
	queue<pair<int,int> > q;
	q.push({x,0});
	int frineds = 0;
	bool check[51] = {false,};
	check[x] = true;
	
	while(!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		q.pop();
		
		for(int i=0; i<vec[now].size(); i++) {
			if(cnt < 2 && !check[vec[now][i]]) {
				check[vec[now][i]] = true;
				frineds = frineds + 1;
				q.push({vec[now][i],cnt+1});
			}
		}
	}	
	answer = max(frineds,answer);
}

void input() {
	cin >> n;
	for(int i=0; i<n; i++) {
		string tmp;
		cin >> tmp;
		for(int j=0; j<n; j++) {
			if(tmp[j] == 'Y') {
				vec[i].push_back(j);
			}
		}
	}
}

void solve() {
	for(int i=0; i<n; i++) {
		bfs(i);
	}
	cout << answer;
}

int main() {
	input();
	solve();
}