#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <cmath> 

using namespace std;

#define INF 200000000

int n;
int person[11];
vector<int> vec[11];
bool check[11];
int answer = INF;
set<int> s_one;
set<int> s_two;

void input() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> person[i];
	}
	
	for(int i=1; i<=n; i++) {
		int cnt;
		cin >> cnt;
		for(int j=0; j<cnt; j++) {
			int tmp; 
			cin >> tmp;
			vec[i].push_back(tmp);
		}
	}
}

void bfs_one(int num) {
	bool c[11] = {false,};
	queue<int> q;
	
	q.push(num);
	c[num] = true;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		s_one.erase(x);
		
		for(int i=0; i<vec[x].size(); i++) {
			int nx = vec[x][i];
			if(check[nx] || c[nx]) { continue; }
			c[nx] = true;
			q.push(nx);
		}
	}
}

void bfs_two() {
	bool c[11] = {false,};
	queue<int> q;
	q.push(1);
	c[1] = true;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		s_two.erase(x);
		
		for(int i=0; i<vec[x].size(); i++) {
			int nx = vec[x][i];
			if(!check[nx] || c[nx]) continue;
			c[nx] = true;
			q.push(nx);
		}
	}
}

void calculate() {
	// 체크 안된 애들 기준으로 bfs 돌려서 잘 도는지 확인
	int tmp = -1;
	int sum1 = 0;
	int sum2 = 0;
	for(int i=1; i<=n; i++) { 
		if(!check[i]) { 
			tmp = i;
			s_one.insert(i); 
			sum1 += person[i];
		} 
		else {
			sum2 += person[i];
			s_two.insert(i);
		}
	}
	
	if(tmp != -1) {
		bfs_one(tmp); 
		bfs_two();
	}
	
	if(s_one.size() == 0 && s_two.size() == 0) {
		answer = min(answer, abs(sum1 - sum2));
	} 
	
	
	s_one.clear();
	s_two.clear();
}

void combination(int idx) {
	calculate();
	
	for(int i=idx; i<=n; i++) {
		if(check[i]) continue;
		check[i] = true;
		combination(idx+1);
		check[i] = false;
	}
}

void solve() {
	check[1] = true;
	
	combination(2);
	
	
	if(answer == INF) {
		answer = -1;
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}