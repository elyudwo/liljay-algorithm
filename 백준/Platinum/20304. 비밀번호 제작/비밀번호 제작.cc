#include <iostream>
#include <queue>
#define INF 1e9
using namespace std;

int arr[1000001];
int n, m;
queue<pair<int, int> > q;

void input() {
	cin >> n;
	cin >> m;
	
	for(int i=0; i<m; i++) {
		int tmp;
		cin >> tmp;
		arr[tmp] = 0;
		q.push({tmp, 0});
	}
	
	for(int i=0; i<=1000000; i++) {
		arr[i] = INF;
	}
}

void solve() {
	int answer = -1;
	
	while(!q.empty()) {
		int x = q.front().first;
		int cnt = q.front().second;
		
		q.pop();
		
		for(int i=0; i<20; i++) {
			int tmp = x;
			tmp ^= 1 << i;
			if(tmp > 1000000) continue;
			
			if(arr[tmp] == INF) {
				arr[tmp] = cnt + 1;
				q.push({tmp, cnt + 1});
			}
		}
	}
	
	for(int i=0; i<=n; i++) {
		answer = max(answer, arr[i]);
	}
	
	cout << answer;
}

int main() {
	input();
	solve();
	
}