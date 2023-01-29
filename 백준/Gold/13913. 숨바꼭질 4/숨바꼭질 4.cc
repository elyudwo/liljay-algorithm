#include <iostream>
#include <deque>
#include <queue>

using namespace std;

int n,k;
bool check[100001];

struct subin {
	int dis;
	int time;
	deque<int> before;
};

void input() {
	cin >> n >> k;
}

void bfs() {
	queue<subin> q;
	deque<int> vec;
	vec.push_back(n);
	q.push({n,0,vec});
	
	check[n] = true;
	
	if(n > k) {
		cout << n - k << '\n';
		for(int i=n; i>=k; i--) {
			cout << i << " ";
		}
		return;
	}
	
	while(!q.empty()) {
		int x = q.front().dis;
		int time = q.front().time;
		deque<int> before = q.front().before;
		q.pop();
		
		if(x == k) {
			cout << time << '\n';
			for(int i=0; i<before.size(); i++) {
				cout << before[i] << " ";
			}
			break;
		}
		
		int dx;
		
		dx = x + 1;
		if(dx <= 100000) {
			if(!check[dx]) {
				before.push_back(dx);
				check[dx] = true;
				q.push({dx,time+1,before});
				before.pop_back();	
			}
		}
		
		
		
		dx = x - 1;
		if(dx >= 0) {
			if(!check[dx]) {
				before.push_back(dx);
				check[dx] = true;
				q.push({dx,time+1,before});
				before.pop_back();		
			}
		}
		
		dx = x * 2;
		if(dx <= 100000) {
			if(!check[dx]) {
				before.push_back(dx);
				check[dx] = true;
				q.push({dx,time+1,before});
				before.pop_back();		
			}
		}
		
	}
}

void solve() {
	bfs();
}

int main() {
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	input();
	solve();
}