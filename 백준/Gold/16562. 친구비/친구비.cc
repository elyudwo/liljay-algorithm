#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n,m,k;
int arr[10001];
vector<int> friends[10001];
vector<pair<int,int> > vec; 
bool check[10001];
int sum = 0;

void input() {
	cin >> n >> m >> k;
	
	for(int i=1; i<=n; i++) {
		int tmp;
		cin >> tmp; 
		vec.push_back({tmp,i});
	}
	
	for(int i=0; i<m; i++) {
		int a,b;
		cin >> a >> b;
		friends[a].push_back(b);
		friends[b].push_back(a);
	}
	
	sort(vec.begin(), vec.end());
}

void bfs(int x) {
	queue<int> q;
	q.push(x);
	check[x] = true;
	
	while(!q.empty()) {
		int tmp = q.front();
		check[tmp] = true;
		q.pop();
		
		for(int i=0; i<friends[tmp].size(); i++) {
			if(!check[friends[tmp][i]]) {
				q.push(friends[tmp][i]);
			}
		}
	}
}

void solve() {
	for(int i=0; i<vec.size(); i++) {
		if(!check[vec[i].second]) {
			bfs(vec[i].second);
			sum = sum + vec[i].first;
		}
		
		if(k < sum) {
			cout << "Oh no";
			return;
		}
	}
	
	cout << sum;
}

int main() {
	input();
	solve();
	
}